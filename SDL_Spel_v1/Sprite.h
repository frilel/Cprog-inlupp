#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

/*
Denna klass tillhör den generella delen.
Detta är en abstrakt klass är för ImmovableSprite och MovableSprite. 
Inga objekt går att skapa utifrån bara denna klass.
Tillämparen måste skapa egna subklasser av ImmovableSprite och MovableSprite för att tillämpningsprogrammet skall kunna skapa objekt.
*/


class Sprite {

public:

	virtual ~Sprite(); // Definierad virtual så att subklasser kan addera sina egna saker som skall destrueras

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites) = 0; // Sprites "tick"-funktion. Tillämpningsprogrammeraren måste själv deklarera denna.
	virtual void render(); // Om en subklass vill implementera animationer kan man behöva ändra denna...

	/* Händelsehanteringar vi låter subklasser deklarera */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}
	
	// Ange förflyttning i x-led och y-led. Adderar värdena till variablerna xpos och ypos
	//virtual void move(int x, int y) { xpos += x; ypos += y; }

	// Standard kollisions-test med alla aktiva sprite-objekt returnerar true om objektet har kolliderat med ett annat
	virtual bool collisionTest(std::vector<Sprite*>& activeSprites);

	// Måste deklareras i subklasser, skall returnera true om spriten är en fiende
	virtual const bool isHostile() const = 0;
	// Playerklassen kommer ändra denna för att identifiera sig som Player
	virtual const bool isPlayer() const { return false; }

	// Används för att markera att en Sprite ska dö
	void kill() { imDead = true; };
	// Används av motorn för att kolla om spriten har dött (skall försvinna)
	const bool isDead() const { return imDead; };

	// Hämtningar av icke-const SDL Objekt
	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();
	SDL_Texture* getTexture() { return objTexture; }
	// Hämtningar av const SDL Objekt, krävs för SDL_HasIntersection() i kollisionsdetekteringen
	const SDL_Rect& getSrcRect() const { return srcRect; }
	const SDL_Rect& getDestRect() const { return destRect; }

	// Positioneringar som används av update() för att uppdatera spritens positioner i spelet
	int& getXpos() { return xpos; }
	int& getYpos() { return ypos; }

	// Hantering av Sprites hastighet
	//const int& getSpeed() const { return moveSpeed; }
	//virtual void setSpeed(int s) { moveSpeed = s; }
	
	// Funktion för Sprite att begära game over till SDLsystem, som i sin tur ger informationen till GameEngine
	void gameOver(bool gameOver) const;

	// Funktioner för att Sprites skall kunna generera egna Sprites. För närvarande implementerat: laser-skott
	void setGeneratedSprite(Sprite* newSprite) { generatedSprite = newSprite; }
	Sprite* getGeneratedSprite() const { return generatedSprite; }
	void nullifyGeneratedSprite() { generatedSprite = nullptr; }
	

protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h); // x,y = startposition i spelet. w,h = storleken på bildkällan. speed = hastighet för spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor förbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator förbjuden
	Sprite() = delete; // Default-konstruktor förbjuden

	SDL_Texture* objTexture; //Sprites texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect är storleken i filen. destRect representarar bilden i spelet

	int xpos; // x-Position för spriten
	int ypos; // y-Position för spriten
	//int moveSpeed; // Hastighet som spriten rör sig

	bool imDead; // Är Spriten död eller levande

	Sprite* generatedSprite; // Sprite-pekare till Sprite-genererad Sprite
};

#endif
