#include "Sprite.h"
#include "TextureManager.h"

Sprite::Sprite(const char* filenamePath, int x, int y, int w, int h){

	objTexture = TextureManager::LoadTexture(filenamePath); //Texture skapas och sparas i objTexture, används av render()

	xpos = x; // startpositionen
	ypos = y;

	srcRect.w = w; //Storleken på rect i bildkällan
	srcRect.h = h;

	srcRect.x = 0; //Rect i bildkällan börjar från 0,0
	srcRect.y = 0;

	destRect.w = srcRect.w * 1; // 1 = kan ändra storlek på 
	destRect.h = srcRect.h * 1;

}

Sprite::~Sprite() {
	SDL_DestroyTexture(objTexture);
}

void Sprite::update(const SDL_Event& event) { // rörelse och händelser sker här!

	switch (event.key.keysym.sym) {
	case SDLK_w: ypos-=8; break;
	case SDLK_s: ypos+=8; break;
	case SDLK_a: xpos-=8; break;
	case SDLK_d: xpos+=8; break;
	}

	destRect.x = xpos; // Spriten rör på sig enligt xpos, ypos
	destRect.y = ypos;

}

void Sprite::render() { // Draw...
	
	if (SDL_RenderCopy(GameEngine::renderer, objTexture, &srcRect, &destRect) != 0)
		//SDL_RenderCopy(GameEngine::renderer, objTexture, &srcRect, &destRect);
	//else
		std::cout << "Failed to render objTexture in Sprite.cpp!" << std::endl; // Fix:fånga error!
}

void keyDown(const SDL_Event& event) {

}