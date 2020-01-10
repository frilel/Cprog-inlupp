#ifndef LASER_H
#define LASER_H

#include "Sprite.h"


class Laser : public Sprite{

public:
	~Laser();

	static Laser* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till player-objekt

	void update(int winW, int winH, std::vector<Sprite*> &activeSprites);

	
	void kill() { imDead = true; }
	const bool isDead() const { return imDead; }
	const bool isHostile() const { return false; }

	virtual bool collisionTest(std::vector<Sprite*> &activeSprites);

protected:

	Laser(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : imDead(false), Sprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Laser(const Laser&) = delete; // Copy-konstruktor förbjuden
	const Laser& operator=(const Laser&) = delete; // Tilldelningsoperator förbjuden

	bool imDead;

};

#endif