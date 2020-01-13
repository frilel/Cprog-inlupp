#ifndef IMMOVABLESPRITE_H
#define IMMOVABLESPRITE_H

#include "Sprite.h"

/*
Denna klass tillhör den generella delen.
Det går att skapa dynamiska objekt av denna klass, men bara i sig gör dessa objekt inget förutom att bara synas på bild.
Tillämparen bör skapa egna subklasser för att definiera objektens karaktär.
*/

class ImmovableSprite : public Sprite {

public:

	virtual ~ImmovableSprite(); // Definierad virtual så att subklasser kan addera sina egna saker som skall destrueras

	static ImmovableSprite* getInstance(const char* filenamePath, int x, int y, int w, int h); // skickar pekare till ImmovableSprite-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*>& activeSprites) {} // Sprites "tick"-funktion. Tillämpningsprogrammeraren måste själv deklarera denna.

	// Måste deklareras i subklasser, skall returnera true om Spriten är en fiende
	virtual const bool isHostile() const { return false; }

	// Kollisions-test med alla aktiva sprite-objekt returnerar true om ImmovableSprite har kolliderat med Player
	//virtual bool collisionTest(std::vector<Sprite*>& activeSprites);

protected:
	ImmovableSprite(const char* filenamePath, int x, int y, int w, int h); // x,y = startposition i spelet. w,h = storleken på bildkällan. speed = hastighet för spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	ImmovableSprite(const ImmovableSprite&) = delete; // Copy-konstruktor förbjuden
	const ImmovableSprite& operator=(const ImmovableSprite&) = delete; // Tilldelningsoperator förbjuden
	ImmovableSprite() = delete; // Default-konstruktor förbjuden

};

#endif