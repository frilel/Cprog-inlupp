#include "Laser.h"
#include <iostream>


Laser::~Laser() {

	std::cout << "Laser destructor!" << std::endl;
}

Laser* Laser::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Laser(filenamePath, x, y, w, h, moveSpeed);
}

void Laser::update(int winW, int winH, std::vector<Sprite*> &activeSprites)
{
	move(0, -getSpeed()); // Lasern åker uppåt (0,-y)
	
	// Laser rör på sig enligt xpos, ypos
	getDestRect().x = getXpos();
	getDestRect().y = getYpos();

	//std::cout << "Laser y-pos:   " << getDestRect().y << std::endl;

	// Om Laser rör sig utanför fönstret UPPTILL
	if ((getDestRect().y + getDestRect().h) < 0) {
		imDead = true; // Försvinn
		std::cout << "Laser Don't Want To Die!" << std::endl;
	}

	imDead = collisionTest(activeSprites);
}

bool Laser::collisionTest(std::vector<Sprite*> &activeSprites) {
	for (Sprite* s : activeSprites) {
		if (s != this) { // kolla inte kollision med sig själv
			if (s->isHostile() == true && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om sprite är hostile och om destRect för Laser skär i destRect för Spriten i vectorn
				std::cout << "Laser collision detected!" << std::endl;
				s->kill();
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}