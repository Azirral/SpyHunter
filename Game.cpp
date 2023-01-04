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
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_UP)
				;//
			else if (event.key.keysym.sym == SDLK_DOWN)
				;//
			else if (event.key.keysym.sym == SDLK_LEFT)
				;//
			else if (event.key.keysym.sym == SDLK_RIGHT)
				;//
			else if (event.key.keysym.sym == SDLK_ESCAPE)
				isRunning = false;
			break;
		case SDL_KEYDOWN:
			//
			break;
		default:
			break;
		}
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
