/*
Sköter inladdning av filer till texturer.

*/

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>


class TextureManager { // flytta detta till något annat??

public:
	static SDL_Texture* LoadTexture(const char* filenamePath);
	static void Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);
};

#endif