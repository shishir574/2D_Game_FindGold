#pragma once
#include<SDL.h>
#include<stdio.h>
#include <iostream>
#include<SDL_image.h>
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title,int width,int height,bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	bool running();
	static SDL_Renderer* renderer;

private:
	int count = 0;
	bool isRunning = false;
	SDL_Window* window;
};

