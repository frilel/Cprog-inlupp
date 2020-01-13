#ifndef SDL_SYSTEM_H
#define SDL_SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>

/*
Tillhör den generella delen.
Klass som hanterar SDL och sköter inladdning av filer till texturer.
Har även hantering av Sprites meddelande om Game Over till spelmotorn. Om det blir fler sådana funktioner i framtiden har jag tänkt skapa en egen Klass för det.
Som används som en brygga mellan Objekt och Motorn.
*/

class SDL_System {

public:

	SDL_System();
	~SDL_System() {}

	bool initSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); // Initiering av SDL. Returnerar false om något gick snett

	void clean(); // För bättre kontroll över rensningen av SDL, än att förlita mig på destruktorn.

	// Returnerar en Texture med vald fil 
	SDL_Texture* LoadTexture(const char* filenamePath);
	// Tar en Texture och skickar till Renderaren
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

	bool gameOver; // Ändras av Sprites. Kontrolleras av GameEngine
}; 

extern SDL_System SDLsystem; // Ett SDL_System objekt som finns för alla att använda
#endif