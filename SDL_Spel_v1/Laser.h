#ifndef LASER_H
#define LASER_H

#include "MovableSprite.h"

/*
Tillämparens subklass till MovableSprite.
Spelarens Laser-skott.
*/

class Laser : public MovableSprite {

public:
	~Laser();

	static Laser* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till player-objekt

	void update(int winW, int winH, std::vector<Sprite*> &activeSprites); // Lasers "tick"

	virtual bool collisionTest(std::vector<Sprite*>& activeSprites);

	// Denna sprite är inte en fiende
	const bool isHostile() const { return false; }

protected:

	Laser(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : MovableSprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Laser(const Laser&) = delete; // Copy-konstruktor förbjuden
	const Laser& operator=(const Laser&) = delete; // Tilldelningsoperator förbjuden

};

#endif