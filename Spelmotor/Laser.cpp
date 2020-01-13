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
	move(0, -getSpeed()); // Lasern �ker upp�t (0,-y)
	
	// Laser r�r p� sig enligt xpos, ypos
	getDestRect().x = getXpos();
	getDestRect().y = getYpos();

	// Om Laser r�r sig utanf�r f�nstret UPPTILL
	if ((getDestRect().y + getDestRect().h) < 0) {
		kill(); // F�rsvinn
	}
	// om jag fortfarande lever: g�r kollisionstest 
	if(isDead() == false) { 
		if (collisionTest(activeSprites)) // Returnerar true om Laser har kolliderat med en fiende
			kill();
	}
}

bool Laser::collisionTest(std::vector<Sprite*> &activeSprites) {
	for (Sprite* s : activeSprites) {
		if (s != this) { // kolla inte kollision med sig sj�lv
			if (s->isHostile() == true && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om sprite �r en fiende och om destRect f�r Laser sk�r i destRect f�r Spriten i vectorn
				std::cout << "Laser collision detected!" << std::endl;
				s->kill(); // Villkorsl�st d�dar den andra Spriten
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}