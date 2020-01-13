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

	// Om Laser rör sig utanför fönstret UPPTILL
	if ((getDestRect().y + getDestRect().h) < 0) {
		kill(); // Försvinn
	}
	// om jag fortfarande lever: gör kollisionstest 
	if(isDead() == false) { 
		if (collisionTest(activeSprites)) // Returnerar true om Laser har kolliderat med en fiende
			kill();
	}
}

bool Laser::collisionTest(std::vector<Sprite*> &activeSprites) {
	for (Sprite* s : activeSprites) {
		if (s != this) { // kolla inte kollision med sig själv
			if (s->isHostile() == true && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om sprite är en fiende och om destRect för Laser skär i destRect för Spriten i vectorn
				std::cout << "Laser collision detected!" << std::endl;
				s->kill(); // Villkorslöst dödar den andra Spriten
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}