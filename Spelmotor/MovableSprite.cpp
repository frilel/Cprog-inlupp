#include "MovableSprite.h"
#include "SDL_System.h"
#include <iostream>


MovableSprite::~MovableSprite() {
	std::cout << "MovableSprite destructor!" << std::endl;
}

MovableSprite::MovableSprite(const char* filenamePath, int x, int y, int w, int h, int mSpeed) : Sprite(filenamePath,x,y,w,h) {

	// initialisera hastigheten
	moveSpeed = mSpeed;
	
}