/*Sköter inladdning av filer till texturer*/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "GameEngine.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* filenamePath);
	static void Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);
};

#endif