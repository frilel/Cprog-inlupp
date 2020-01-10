#include "Sprite.h"
#include "SDL_System.h"
//#include "GameEngine.h"
#include <iostream>

Sprite::~Sprite() {
	SDL_DestroyTexture(objTexture);
	std::cout << "Sprite deconstructed, objTexture destroyed..." << std::endl;
}

Sprite::Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : generatedSprite(nullptr) {
	
	objTexture = SDLsystem.LoadTexture(filenamePath); //Texture skapas och sparas i objTexture, används av render()
	std::cout << "objTexture loaded with: " << filenamePath << std::endl;


	// initialisera hastigheten
	speed = moveSpeed;

	// startpositionen
	xpos = x; 
	ypos = y;

	// Storleken på rect i bildkällan
	srcRect.w = w; 
	srcRect.h = h;

	// Placering av rect i bildkällan börjar 0,0 uppe i vänster
	srcRect.x = 0; 
	srcRect.y = 0;

	// storleken på rect i programmet blir lika stor som i bildkällan
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h;
	
}
/*
void Sprite::update(int winW, int winH, std::vector<Sprite*> &activeSprites) { // rörelse och händelser sker här! TA EMOT GameEngine OCH KOLLA KOLLISION MED WINDOW OCH ANDRA SPRITES ?
	std::cout << "Sprite update in Sprite.cpp!" << std::endl;
	// Spriten rör på sig enligt xpos, ypos som standard
	destRect.x = xpos; 
	destRect.y = ypos;

}*/

void Sprite::render() { // Draw...
	SDLsystem.Draw(objTexture, srcRect, destRect);

}

SDL_Rect& Sprite::getSrcRect() {
	return const_cast<SDL_Rect&>(static_cast<const Sprite&>(*this).getSrcRect());
}

SDL_Rect& Sprite::getDestRect() {
	return const_cast<SDL_Rect&>(static_cast<const Sprite&>(*this).getDestRect());
}

bool Sprite::collisionTest(std::vector<Sprite*> &activeSprites) {
	for (Sprite* s : activeSprites) {
		if (s != this) { // kolla inte kollision med sig själv
			if (SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om destRect för Sprite skär i destRect för Sprite i vectorn
				std::cout << "Sprite collision detected!" << std::endl;
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}

void Sprite::gameOver(bool gameOver) const {
	SDLsystem.spriteWantsGameOver(gameOver);
}
