#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"

class Enemy : public Sprite
{
public:

	static Enemy* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till Enemy-objekt

	void update(GameEngine*);

protected:
	Enemy(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : Sprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	Enemy(const Enemy&) = delete; // Copy-konstruktor förbjuden
	const Enemy& operator=(const Enemy&) = delete; // Tilldelningsoperator förbjuden

};

#endif