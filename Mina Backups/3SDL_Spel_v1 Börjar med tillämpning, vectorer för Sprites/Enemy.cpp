#include "Enemy.h"

Enemy* Enemy::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Enemy(filenamePath, x, y, w, h, moveSpeed);
}

void Enemy::update(GameEngine* gameEngine) { // rörelse och händelser sker här! -Vi bör ta med argument som hanterar hur vi ska röra oss?

	move(0, getSpeed()); // just nu flyttar sig alla fiender bara i y-led

	// En vanlig Sprites rörelse är "oändlig", är den på väg ut ur fönstret förflyttas till andra sidan av fönstret.
	// Om Sprite rör sig utanför fönstret VÄNSTER
	if ((getXpos() + getDestRect().w) < 0)
		getXpos() += gameEngine->getWindowWidth(); // Flyttar sig till Höger sida
	// Om Sprite rör sig utanför fönstret HÖGER
	if (getXpos() > gameEngine->getWindowWidth())
		getXpos() -= gameEngine->getWindowWidth(); // Flyttar sig till Vänster sida
	// Om Sprite rör sig utanför fönstret UPPTILL
	if ((getYpos() + getDestRect().h) < 0)
		getYpos() += gameEngine->getWindowHeight(); // Flyttar sig till Nedre sida
	// Om Sprite rör sig utanför fönstret NEDTILL
	if (getYpos() > gameEngine->getWindowHeight())
		getYpos() -= gameEngine->getWindowHeight(); // Flyttar sig till Övre sida

	getDestRect().x = getXpos(); // Spriten rör på sig enligt xpos, ypos
	getDestRect().y = getYpos();
}