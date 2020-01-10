#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>



class GameEngine {

public:
	GameEngine() : counter(0), isRunning(true), window(nullptr), windowWidth(0), windowHeight(0) {};
	~GameEngine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update(GameEngine*);
	void render();
	void clean();

	int getWindowWidth() { return windowWidth; }
	int getWindowHeight() { return windowHeight; }

	bool& running() { return isRunning; }

	static SDL_Renderer* renderer; // renderare som allt i vår motor kan använda

private:
	
	GameEngine(const GameEngine&) = delete; // Copy-konstruktor förbjuden
	const GameEngine& operator=(const GameEngine&) = delete; // Tilldelningsoperator förbjuden
	
	int counter;
	bool isRunning;
	SDL_Window* window;
	
	int windowWidth;
	int windowHeight;

};

#endif GAME_H