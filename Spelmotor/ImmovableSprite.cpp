#include "ImmovableSprite.h"
#include "SDL_System.h"
#include <iostream>


ImmovableSprite::~ImmovableSprite() {
	std::cout << "MovableSprite destructor!" << std::endl;
}

ImmovableSprite::ImmovableSprite(const char* filenamePath, int x, int y, int w, int h) : Sprite(filenamePath, x, y, w, h) {

	// ImmovableSprites fasta position
	getDestRect().x = x;
	getDestRect().y = y;

}

ImmovableSprite* ImmovableSprite::getInstance(const char* filenamePath, int x, int y, int w, int h)
{
	return new ImmovableSprite(filenamePath, x, y, w, h);
}

