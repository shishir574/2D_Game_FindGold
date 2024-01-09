#pragma once
#include<iostream>
#include<SDL.h>
#include"Game.h"


class GameObject
{
public:
	GameObject(const char* texturesheet,int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int x_pos;
	int y_pos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};

