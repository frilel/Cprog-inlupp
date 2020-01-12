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
	
	move(0, getSpeed()); // Tillämpningsprogrammeraren har valt att Enemy bara rör sig neråt (0,+y) med vald moveSpeed

	// En vanlig Enemys rörelse är "oändlig", är den på väg ut ur fönstret förflyttas till andra sidan av fönstret.
	// Om Sprite rör sig utanför fönstret NEDTILL
	if (getYpos() > winH)
 		move(0, -(winH + getDestRect().h)); // Flyttar sig till Övre sida

	getDestRect().x = getXpos(); // Spriten rör på sig enligt xpos, ypos
	getDestRect().y = getYpos();

	if (isDead() == false) // om jag fortfarande lever: gör kollisionstest
		if (collisionTest(activeSprites)) // Returnerar true vid kollision med sprite som inte är "hostile"
			kill();

}

bool Enemy::collisionTest(std::vector<Sprite*> &sprites) { // Enemy deklarerar en egen collisionTest som ser till att två fiender inte dör om de kolliderar med varandra
	for (Sprite* s : sprites) {
		if (s != this) { // kolla inte kollision med sig själv
			if (s->isHostile() == false && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om spriten i vectorn inte är en annan Enemy och destRect för Enemy skär i destRect för Sprite i vectorn
				std::cout << "Enemy collision detected!" << std::endl;
				s->kill(); // Villkorslöst dödar den andra kolliderande Spriten
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}