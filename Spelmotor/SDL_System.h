#ifndef SDL_SYSTEM_H
#define SDL_SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>

/*
Tillh�r den generella delen.
Klass som hanterar SDL och sk�ter inladdning av filer till texturer.
Har �ven hantering av Sprites meddelande om Game Over till spelmotorn. Om det blir fler s�dana funktioner i framtiden har jag t�nkt skapa en egen Klass f�r det.
Som anv�nds som en brygga mellan Objekt och Motorn.
*/

class SDL_System {

public:

	SDL_System();
	~SDL_System() {}

	bool initSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); // Initiering av SDL. Returnerar false om n�got gick snett

	void clean(); // F�r b�ttre kontroll �ver rensningen av SDL, �n att f�rlita mig p� destruktorn.

	// Returnerar en Texture med vald fil 
	SDL_Texture* LoadTexture(const char* filenamePath);
	// Tar en Texture och skickar till Renderaren
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

	bool gameOver; // �ndras av Sprites. Kontrolleras av GameEngine
}; 

extern SDL_System SDLsystem; // Ett SDL_System objekt som finns f�r alla att anv�nda
#endif