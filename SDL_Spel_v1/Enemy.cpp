#include "Enemy.h"
#include "SDL_System.h"
#include <iostream>

Enemy::~Enemy() {

	std::cout << "Enemy destructor!" << std::endl;
}

Enemy* Enemy::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Enemy(filenamePath, x, y, w, h, moveSpeed);
}

void Enemy::update(int winW, int winH, std::vector<Sprite*> &activeSprites) { // rörelse och händelser sker här! -Vi bör ta med argument som hanterar hur vi ska röra oss?
	
	move(0, getSpeed()); // Enemy rör sig neråt (0,y)

	// En vanlig Enemys rörelse är "oändlig", är den på väg ut ur fönstret förflyttas till andra sidan av fönstret.
	// Om Sprite rör sig utanför fönstret VÄNSTER
	if ((getXpos() + getDestRect().w) < 0)
		getXpos() += winW; // Flyttar sig till Höger sida

	// Om Sprite rör sig utanför fönstret HÖGER
	if (getXpos() > winW)
		getXpos() -= winW; // Flyttar sig till Vänster sida

	// Om Sprite rör sig utanför fönstret UPPTILL
	if ((getYpos() + getDestRect().h) < 0)
		getYpos() += winH; // Flyttar sig till Nedre sida

	// Om Sprite rör sig utanför fönstret NEDTILL
	if (getYpos() > winH)
		getYpos() -= winH; // Flyttar sig till Övre sida

	getDestRect().x = getXpos(); // Spriten rör på sig enligt xpos, ypos
	getDestRect().y = getYpos();

	imDead = collisionTest(activeSprites); // Returnerar true vid kollision med sprite som inte är "hostile"

}

bool Enemy::collisionTest(std::vector<Sprite*> &sprites) { // Enemy deklarerar en egen collisionTest för att två fiender inte ska dö om de kolliderar med varandra
	for (Sprite* s : sprites) {
		if (s != this) { // kolla inte kollision med sig själv
			if (s->isHostile() == false && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om spriten i vectorn inte är en annan Enemy och destRect för Sprite skär i destRect för Sprite i vectorn
				std::cout << "Enemy collision detected!" << std::endl;
				s->kill(); // fungerar inte
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}