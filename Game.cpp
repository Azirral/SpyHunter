#include "Game.h"

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	isRunning = false;
	screenWidth = SCREEN_WIDTH;
	screenHeight = SCREEN_HEIGHT;
}

void Game::initialize(const char* title, int x, int y, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		exit(1);
	}
	window = SDL_CreateWindow(title, x, y, width, height, 0);
	if (window == nullptr) {
		SDL_Quit();
		printf("SDL_CreateWindow error: %s\n", SDL_GetError());
		exit(1);
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr) {
		SDL_Quit();
		printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	isRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYUP:
		//
		break;
	case SDL_KEYDOWN:
		//
		break;
	case SDLK_LEFT:
		//do sprawdzenia czy dzia³a czy trzeba magic pozmieniaæ
		break; 
	case SDLK_RIGHT:
			//do sprawdzenia czy dzia³a czy trzeba magic pozmieniaæ
			break;
	case SDLK_ESCAPE:
		//do sprawdzenia czy dzia³a czy trzeba magic pozmieniaæ
		break;
	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//tutaj dodawanie rzeczy do rendera
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::checkIfRunning()
{
	return isRunning;
}

Game::~Game()
{
}
