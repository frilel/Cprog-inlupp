#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
//#include "GameEngine.h"


/*Denna klass är för Objekt i världen, som spelaren och fienden*/


class Sprite {

public:

	virtual ~Sprite(); // Inget mer som behövs tas bort? rect?

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites) = 0; // deklarera = 0 ?
	virtual void render();

	/* Händelsehanteringar */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}

	// hämtningar av icke-const SDL Objekt
	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();
	SDL_Texture* getTexture() { return objTexture; }

	// hämtningar av const SDL Objekt, krävs för SDL_HasIntersection()
	const SDL_Rect& getSrcRect() const { return srcRect; }
	const SDL_Rect& getDestRect() const { return destRect; }

	// Positioneringar
	int& getXpos() { return xpos; }
	int& getYpos() { return ypos; }

	// Hastighet
	int& getSpeed() { return speed; }

	// Rörelse
	virtual void move(int x, int y) { xpos += x; ypos += y; } // addera (x) till xpos och (y) till ypos. Tänkt att vara det enda sättet att flytta vår sprite efter instansiering
	
	// Standard kollisions-test med alla aktiva sprite-objekt returnerar true om objektet har kolliderat med ett annat
	virtual bool collisionTest(std::vector<Sprite*> &activeSprites);

	// Måste deklareras i subklasser, används för att markera en Sprite som död
	virtual void kill() = 0;
	// Måste deklareras i subklasser, används av motorn för att kolla om spriten har dött (skall försvinna)
	virtual const bool isDead() const = 0; 
	// Måste deklareras i subklasser, skall returnera true om spriten är en fiende
	virtual const bool isHostile() const = 0; 

	// Funktion för sprite att begära game over
	void gameOver(bool gameOver) const;

	// Funktioner för att främst generera laser-skott
	void setGeneratedSprite(Sprite* newSprite) { generatedSprite = newSprite; }
	Sprite* getGeneratedSprite() const { return generatedSprite; }
	void nullifyGeneratedSprite() { generatedSprite = nullptr; }
	

protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // x,y = startposition i spelet. w,h = storleken på bildkällan. speed = hastighet för spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor förbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator förbjuden

	Sprite* generatedSprite;

	SDL_Texture* objTexture; //Spritens texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect är storleken i filen. destRect representarar bilden i spelet

	int speed; // Hastighet som spriten rör sig

	int xpos; // x-Position för spriten
	int ypos; // y-Position för spriten

};

#endif
