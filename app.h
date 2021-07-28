#pragma once
#include <SDL.h>
#include <array>

class App
{
public:
	App();
	bool init();
	int loop();
	void input(SDL_Event*);
	void update();
	void render();
	void exit();

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};