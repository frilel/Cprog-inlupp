#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H

#include "Sprite.h"

/*
Denna klass tillhör den generella delen. Med möjlighet att röra på sig, m.h.a. funktionen move(int x, int y).
Det går inte att skapa dynamiska objekt av denna klass, då jag önskar att tillämparen skapar egna subklasser för att definiera objektens karaktär.
*/

class MovableSprite : public Sprite {

public:

	virtual ~MovableSprite(); // Definierad virtual så att subklasser kan addera sina egna saker som skall destrueras

	virtual void update(int winW, int winH, std::vector<Sprite*>& activeSprites) = 0; // Sprites "tick"-funktion. Tillämpningsprogrammeraren måste själv deklarera denna.

	// Ange förflyttning i x-led och y-led. Adderar värdena till variablerna xpos och ypos
	virtual void move(int x, int y) { getXpos() += x; getYpos() += y; }

	// Måste deklareras i subklasser, skall returnera true om spriten är en fiende
	virtual const bool isHostile() const = 0;

	// Hantering av Sprites hastighet
	const int& getSpeed() const { return moveSpeed; }
	virtual void setSpeed(int s) { moveSpeed = s; }

protected:
	MovableSprite(const char* filenamePath, int x, int y, int w, int h, int speed); // x,y = startposition i spelet. w,h = storleken på bildkällan. speed = hastighet för spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	MovableSprite(const MovableSprite&) = delete; // Copy-konstruktor förbjuden
	const MovableSprite& operator=(const MovableSprite&) = delete; // Tilldelningsoperator förbjuden
	MovableSprite() = delete; // Default-konstruktor förbjuden

	int moveSpeed; // Hastighet som spriten rör sig

};

#endif