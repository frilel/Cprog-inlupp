/*
Sk�ter inladdning av filer till texturer.

*/

#ifndef SDL_SYSTEM_H
#define SDL_SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>


class SDL_System { // flytta detta till n�got annat??

public:

	SDL_System();
	~SDL_System() {}

	bool initSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void clean();

	SDL_Texture* LoadTexture(const char* filenamePath);
	void Draw(SDL_Texture* texture,  SDL_Rect srcRect, SDL_Rect destRect);

	SDL_Renderer* getRenderer() const { return renderer; }

	// Anv�nds av GameEngine f�r att kolla om n�gon sprite har meddelat game over
	const bool isItGameOver() const { return gameOver; }
	// Anv�nds av Sprites f�r att beg�ra game over
	void spriteWantsGameOver(bool itsOver) { gameOver = itsOver; }

private:

	SDL_System(const SDL_System&) = delete; // Copy-konstruktor f�rbjuden
	const SDL_System& operator=(const SDL_System&) = delete; // Tilldelningsoperator f�rbjuden

	SDL_Window* window;
	SDL_Renderer* renderer;

	bool gameOver;
}; 

extern SDL_System SDLsystem;
#endif