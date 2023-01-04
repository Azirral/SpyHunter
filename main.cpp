#include "Game.h"

int main() {
	Game* game = new Game();
	game->initialize("Adam Sobczuk, 188656", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
	while (game->checkIfRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	/*while (game is running) {
		handle any user input
		update all objects e.g. positions etc.
		render changes to the display
	}*/
	return 0;
}