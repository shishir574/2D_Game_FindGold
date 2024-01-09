#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Maps.h"
#include "Components.h"
#include "ECS.h"

GameObject* player;
GameObject* gold;
Maps* map;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title,int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << " Subsystems initialized \n";
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			cout << " Window Created successfully \n";
		}
		renderer = SDL_CreateRenderer(window, -1, flags);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << " Renderer Created successfully \n";
		}
		isRunning = true;
	}
	player = new GameObject("assets/player_boy.png",0,0);
	gold = new GameObject("assets/gold_bar.png", 64, 64);
	map = new Maps();
	newPlayer.addComponent<PositionComponent>();
}

void Game:: update()
{
	player->update();
	gold->update();
	manager.update();
	cout << newPlayer.getComponent<PositionComponent>().x() << " , " << newPlayer.getComponent<PositionComponent>().y()<<endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::render()
{
	SDL_RenderClear(Game::renderer);
	map->drawMap();
	player->render();
	gold->render();
	SDL_RenderPresent(Game::renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_QUIT;
	cout << " GAME CLEANED \n";
}

bool Game::running()
{
	return isRunning;
}
