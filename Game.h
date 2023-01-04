#pragma once
extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}
#include <stdio.h>

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	int screenWidth, screenHeight;
public:
	Game();
	void initialize(const char* title, int x, int y, int width, int height);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool checkIfRunning();
	~Game();
};

