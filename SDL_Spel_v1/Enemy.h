#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"

class Enemy : public Sprite
{
public:

	virtual ~Enemy();
	static Enemy* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till Enemy-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites);

	virtual bool collisionTest(std::vector<Sprite*> &activeSprites);

	// D�da spriten
	void kill() { imDead = true; }
	const bool isDead() const { return imDead; }
	const bool isHostile() const { return true; } // Returneras endast av fiender

protected:
	Enemy(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : imDead(false), Sprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Enemy(const Enemy&) = delete; // Copy-konstruktor f�rbjuden
	const Enemy& operator=(const Enemy&) = delete; // Tilldelningsoperator f�rbjuden

	bool imDead;
};

#endif