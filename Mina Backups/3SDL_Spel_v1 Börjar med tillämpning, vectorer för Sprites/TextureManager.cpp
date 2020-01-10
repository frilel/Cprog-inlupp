/*
Sköter inladdning av filer till texturer.

*/

#include "TextureManager.h"
#include "GameEngine.h"

SDL_Texture* TextureManager::LoadTexture(const char* filenamePath) { // tar path till file och 
	SDL_Surface* tempSurface = IMG_Load(filenamePath); // laddar i en surface som 
	if (tempSurface == NULL) {
		std::cout << filenamePath << " could not be loaded! SDL Error: " << std::endl << SDL_GetError() << std::endl;
		//running() = false;   //VARFÖR FUNKAR DEN EJ?
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(GameEngine::renderer, tempSurface); // renderas i en texture vilket sedan returneras. Försvinner texture sen???
	SDL_FreeSurface(tempSurface); // Surface tas bort

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect) { // Medskickade texturen renderas i GameEngine::renderer
	SDL_RenderCopy(GameEngine::renderer, texture, &srcRect, &destRect);

}