#include "GameObject.h"
#include"TextureManager.h"
#define ScaleFactor 4

GameObject::GameObject(const char* texturesheet,int x,int y)
{
	objTexture = TextureManager::loadTexture(texturesheet);
	x_pos = x;
	y_pos = y;
}

void GameObject::update()
{
	x_pos++;
	y_pos++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x_pos;
	destRect.y = y_pos;
	destRect.h = srcRect.h * ScaleFactor;
	destRect.w = srcRect.w * ScaleFactor;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}