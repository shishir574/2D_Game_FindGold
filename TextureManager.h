#pragma once
#include<SDL.h>
#include<iostream>
#include"Game.h"
using namespace std;



class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};

