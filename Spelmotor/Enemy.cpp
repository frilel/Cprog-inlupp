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

void Enemy::update(int winW, int winH, std::vector<Sprite*> &activeSprites) { // r�relse och h�ndelser sker h�r! -Vi b�r ta med argument som hanterar hur vi ska r�ra oss?
	
	move(0, getSpeed()); // Till�mpningsprogrammeraren har valt att Enemy bara r�r sig ner�t (0,+y) med vald moveSpeed

	// En vanlig Enemys r�relse �r "o�ndlig", �r den p� v�g ut ur f�nstret f�rflyttas till andra sidan av f�nstret.
	// Om Sprite r�r sig utanf�r f�nstret NEDTILL
	if (getYpos() > winH)
 		move(0, -(winH + getDestRect().h)); // Flyttar sig till �vre sida

	getDestRect().x = getXpos(); // Spriten r�r p� sig enligt xpos, ypos
	getDestRect().y = getYpos();

	if (isDead() == false) // om jag fortfarande lever: g�r kollisionstest
		if (collisionTest(activeSprites)) // Returnerar true vid kollision med sprite som inte �r "hostile"
			kill();

}

bool Enemy::collisionTest(std::vector<Sprite*> &sprites) { // Enemy deklarerar en egen collisionTest som ser till att tv� fiender inte d�r om de kolliderar med varandra
	for (Sprite* s : sprites) {
		if (s != this) { // kolla inte kollision med sig sj�lv
			if (s->isHostile() == false && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om spriten i vectorn inte �r en annan Enemy och destRect f�r Enemy sk�r i destRect f�r Sprite i vectorn
				std::cout << "Enemy collision detected!" << std::endl;
				s->kill(); // Villkorsl�st d�dar den andra kolliderande Spriten
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}