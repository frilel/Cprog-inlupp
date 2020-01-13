#ifndef IMMOVABLESPRITE_H
#define IMMOVABLESPRITE_H

#include "Sprite.h"

/*
Denna klass tillh�r den generella delen.
Det g�r att skapa dynamiska objekt av denna klass, men bara i sig g�r dessa objekt inget f�rutom att bara synas p� bild.
Till�mparen b�r skapa egna subklasser f�r att definiera objektens karakt�r.
*/

class ImmovableSprite : public Sprite {

public:

	virtual ~ImmovableSprite(); // Definierad virtual s� att subklasser kan addera sina egna saker som skall destrueras

	static ImmovableSprite* getInstance(const char* filenamePath, int x, int y, int w, int h); // skickar pekare till ImmovableSprite-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*>& activeSprites) {} // Sprites "tick"-funktion. Till�mpningsprogrammeraren m�ste sj�lv deklarera denna.

	// M�ste deklareras i subklasser, skall returnera true om Spriten �r en fiende
	virtual const bool isHostile() const { return false; }

	// Kollisions-test med alla aktiva sprite-objekt returnerar true om ImmovableSprite har kolliderat med Player
	//virtual bool collisionTest(std::vector<Sprite*>& activeSprites);

protected:
	ImmovableSprite(const char* filenamePath, int x, int y, int w, int h); // x,y = startposition i spelet. w,h = storleken p� bildk�llan. speed = hastighet f�r spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	ImmovableSprite(const ImmovableSprite&) = delete; // Copy-konstruktor f�rbjuden
	const ImmovableSprite& operator=(const ImmovableSprite&) = delete; // Tilldelningsoperator f�rbjuden
	ImmovableSprite() = delete; // Default-konstruktor f�rbjuden

};

#endif