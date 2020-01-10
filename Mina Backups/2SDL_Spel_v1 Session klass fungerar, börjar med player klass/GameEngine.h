#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Sprite.h"
#include "Map.h"

class GameEngine {

public:
	GameEngine();
	~GameEngine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents(); // anv�nds inte nu, allt l�ggs i update atm
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer; // renderare som allt i v�r motor kan anv�nda

private:
	int counter = 0;
	bool isRunning = true;
	SDL_Window* window;
	

};

#endif GAME_H