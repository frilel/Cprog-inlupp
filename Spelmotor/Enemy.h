#ifndef ENEMY_H
#define ENEMY_H

#include "MovableSprite.h"

/*
Tillämparens subklass till MovableSprite.
Fiendernas karaktär.
*/

class Enemy : public MovableSprite
{
public:

	virtual ~Enemy();
	static Enemy* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till Enemy-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites); // Enemys "tick"

	// Enemys egna kollisionstest
	virtual bool collisionTest(std::vector<Sprite*> &activeSprites);

	// Spriten är en fiende och returnerar true
	const bool isHostile() const { return true; }

protected:
	Enemy(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : MovableSprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Enemy(const Enemy&) = delete; // Copy-konstruktor förbjuden
	const Enemy& operator=(const Enemy&) = delete; // Tilldelningsoperator förbjuden
	
};

#endif