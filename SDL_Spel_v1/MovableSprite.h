#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H

#include "Sprite.h"

/*
Denna klass tillh�r den generella delen. Med m�jlighet att r�ra p� sig, m.h.a. funktionen move(int x, int y).
Det g�r inte att skapa dynamiska objekt av denna klass, d� jag �nskar att till�mparen skapar egna subklasser f�r att definiera objektens karakt�r.
*/

class MovableSprite : public Sprite {

public:

	virtual ~MovableSprite(); // Definierad virtual s� att subklasser kan addera sina egna saker som skall destrueras

	virtual void update(int winW, int winH, std::vector<Sprite*>& activeSprites) = 0; // Sprites "tick"-funktion. Till�mpningsprogrammeraren m�ste sj�lv deklarera denna.

	// Ange f�rflyttning i x-led och y-led. Adderar v�rdena till variablerna xpos och ypos
	virtual void move(int x, int y) { getXpos() += x; getYpos() += y; }

	// M�ste deklareras i subklasser, skall returnera true om spriten �r en fiende
	virtual const bool isHostile() const = 0;

	// Hantering av Sprites hastighet
	const int& getSpeed() const { return moveSpeed; }
	virtual void setSpeed(int s) { moveSpeed = s; }

protected:
	MovableSprite(const char* filenamePath, int x, int y, int w, int h, int speed); // x,y = startposition i spelet. w,h = storleken p� bildk�llan. speed = hastighet f�r spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	MovableSprite(const MovableSprite&) = delete; // Copy-konstruktor f�rbjuden
	const MovableSprite& operator=(const MovableSprite&) = delete; // Tilldelningsoperator f�rbjuden
	MovableSprite() = delete; // Default-konstruktor f�rbjuden

	int moveSpeed; // Hastighet som spriten r�r sig

};

#endif