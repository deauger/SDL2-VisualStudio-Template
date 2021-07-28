#include "app.h"
#include <iostream>

App::App()
{
	isRunning = true;
	window = NULL;
	renderer = NULL;
}

bool App::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("Loop", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
		if (window != NULL)
		{
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	return true;
}

int App::loop()
{
	SDL_Event event;
	if (init() == false)
	{
		return -1;
	}
	while (isRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			input(&event);
		}
		update();
		render();
	}
	exit();
	return 0;
}

void App::input(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void App::update()
{

}

void App::render()
{
	SDL_Delay(1);
}

void App::exit()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
}