/*
Sköter inladdning av filer till texturer.

*/

#include "SDL_System.h"
#include <iostream>

SDL_System SDLsystem;

SDL_System::SDL_System() : window(nullptr), renderer(nullptr), gameOver(false) {
	std::cout << "SDLsystem constructed!!!!" << std::endl;
}


void SDL_System::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "SDL-systems cleaned!" << std::endl;
}

bool SDL_System::initSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "SDL-systems Initializing!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window == NULL) {
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else {
			std::cout << "Window created!" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
		}

		if (renderer == NULL) {
			std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		std::cout << "SDL-systems Initialized!" << std::endl;
		return true;
	} //initialize
	else {
		return false;
		std::cout << "SDL_Init failed! SDL Error: " << SDL_GetError() << std::endl;
	}

}

SDL_Texture* SDL_System::LoadTexture(const char* filenamePath) { // tar path till en fil och laddar i en texture

	SDL_Surface* tempSurface = IMG_Load(filenamePath); // laddar i en surface som 
	if (tempSurface == NULL) {
		std::cout << filenamePath << " could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface); // surface skapas i en texture vilket sedan returneras
	if (texture == NULL) {
		std::cout << "SDL_CreateTextureFromSurface returned NULL! SDL Error: " << SDL_GetError() << std::endl;
	}

	SDL_FreeSurface(tempSurface); // Surface tas bort
	std::cout << "Texture created in SDL_System!" << std::endl;

	return texture;
}

void SDL_System::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect){ // Medskickade texturen renderas i GameEngine::renderer
	if(SDL_RenderCopy(renderer, texture, &srcRect, &destRect) != 0)
		std::cout << "Failed to render Texture in SDL_System: " << SDL_GetError() << std::endl;
}
