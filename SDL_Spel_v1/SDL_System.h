/*
Sköter inladdning av filer till texturer.

*/

#ifndef SDL_SYSTEM_H
#define SDL_SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>


class SDL_System { // flytta detta till något annat??

public:

	SDL_System();
	~SDL_System() {}

	bool initSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void clean();

	SDL_Texture* LoadTexture(const char* filenamePath);
	void Draw(SDL_Texture* texture,  SDL_Rect srcRect, SDL_Rect destRect);

	SDL_Renderer* getRenderer() const { return renderer; }

	// Används av GameEngine för att kolla om någon sprite har meddelat game over
	const bool isItGameOver() const { return gameOver; }
	// Används av Sprites för att begära game over
	void spriteWantsGameOver(bool itsOver) { gameOver = itsOver; }

private:

	SDL_System(const SDL_System&) = delete; // Copy-konstruktor förbjuden
	const SDL_System& operator=(const SDL_System&) = delete; // Tilldelningsoperator förbjuden

	SDL_Window* window;
	SDL_Renderer* renderer;

	bool gameOver;
}; 

extern SDL_System SDLsystem;
#endif