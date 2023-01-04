#include "Game.h"

int main(int argc, char** argv) {
	Game* game = new Game();
	game->initialize("Adam Sobczuk, 188656", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
	while (game->checkIfRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
} 
