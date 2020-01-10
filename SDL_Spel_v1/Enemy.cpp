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
	
	move(0, getSpeed()); // Enemy r�r sig ner�t (0,y)

	// En vanlig Enemys r�relse �r "o�ndlig", �r den p� v�g ut ur f�nstret f�rflyttas till andra sidan av f�nstret.
	// Om Sprite r�r sig utanf�r f�nstret V�NSTER
	if ((getXpos() + getDestRect().w) < 0)
		getXpos() += winW; // Flyttar sig till H�ger sida

	// Om Sprite r�r sig utanf�r f�nstret H�GER
	if (getXpos() > winW)
		getXpos() -= winW; // Flyttar sig till V�nster sida

	// Om Sprite r�r sig utanf�r f�nstret UPPTILL
	if ((getYpos() + getDestRect().h) < 0)
		getYpos() += winH; // Flyttar sig till Nedre sida

	// Om Sprite r�r sig utanf�r f�nstret NEDTILL
	if (getYpos() > winH)
		getYpos() -= winH; // Flyttar sig till �vre sida

	getDestRect().x = getXpos(); // Spriten r�r p� sig enligt xpos, ypos
	getDestRect().y = getYpos();

	imDead = collisionTest(activeSprites); // Returnerar true vid kollision med sprite som inte �r "hostile"

}

bool Enemy::collisionTest(std::vector<Sprite*> &sprites) { // Enemy deklarerar en egen collisionTest f�r att tv� fiender inte ska d� om de kolliderar med varandra
	for (Sprite* s : sprites) {
		if (s != this) { // kolla inte kollision med sig sj�lv
			if (s->isHostile() == false && SDL_HasIntersection(&getDestRect(), &s->getDestRect())) { // Kontrollerar om spriten i vectorn inte �r en annan Enemy och destRect f�r Sprite sk�r i destRect f�r Sprite i vectorn
				std::cout << "Enemy collision detected!" << std::endl;
				s->kill(); // fungerar inte
				return true; // Kollision sant
			}
		}
	}
	return false; // Kollision falskt
}