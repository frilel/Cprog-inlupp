#include "Enemy.h"

Enemy* Enemy::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Enemy(filenamePath, x, y, w, h, moveSpeed);
}

void Enemy::update(GameEngine* gameEngine) { // r�relse och h�ndelser sker h�r! -Vi b�r ta med argument som hanterar hur vi ska r�ra oss?

	move(0, getSpeed()); // just nu flyttar sig alla fiender bara i y-led

	// En vanlig Sprites r�relse �r "o�ndlig", �r den p� v�g ut ur f�nstret f�rflyttas till andra sidan av f�nstret.
	// Om Sprite r�r sig utanf�r f�nstret V�NSTER
	if ((getXpos() + getDestRect().w) < 0)
		getXpos() += gameEngine->getWindowWidth(); // Flyttar sig till H�ger sida
	// Om Sprite r�r sig utanf�r f�nstret H�GER
	if (getXpos() > gameEngine->getWindowWidth())
		getXpos() -= gameEngine->getWindowWidth(); // Flyttar sig till V�nster sida
	// Om Sprite r�r sig utanf�r f�nstret UPPTILL
	if ((getYpos() + getDestRect().h) < 0)
		getYpos() += gameEngine->getWindowHeight(); // Flyttar sig till Nedre sida
	// Om Sprite r�r sig utanf�r f�nstret NEDTILL
	if (getYpos() > gameEngine->getWindowHeight())
		getYpos() -= gameEngine->getWindowHeight(); // Flyttar sig till �vre sida

	getDestRect().x = getXpos(); // Spriten r�r p� sig enligt xpos, ypos
	getDestRect().y = getYpos();
}