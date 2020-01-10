#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
//#include "GameEngine.h"


/*Denna klass �r f�r Objekt i v�rlden, som spelaren och fienden*/


class Sprite {

public:

	virtual ~Sprite(); // Inget mer som beh�vs tas bort? rect?

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites) = 0; // deklarera = 0 ?
	virtual void render();

	/* H�ndelsehanteringar */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}

	// h�mtningar av icke-const SDL Objekt
	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();
	SDL_Texture* getTexture() { return objTexture; }

	// h�mtningar av const SDL Objekt, kr�vs f�r SDL_HasIntersection()
	const SDL_Rect& getSrcRect() const { return srcRect; }
	const SDL_Rect& getDestRect() const { return destRect; }

	// Positioneringar
	int& getXpos() { return xpos; }
	int& getYpos() { return ypos; }

	// Hastighet
	int& getSpeed() { return speed; }

	// R�relse
	virtual void move(int x, int y) { xpos += x; ypos += y; } // addera (x) till xpos och (y) till ypos. T�nkt att vara det enda s�ttet att flytta v�r sprite efter instansiering
	
	// Standard kollisions-test med alla aktiva sprite-objekt returnerar true om objektet har kolliderat med ett annat
	virtual bool collisionTest(std::vector<Sprite*> &activeSprites);

	// M�ste deklareras i subklasser, anv�nds f�r att markera en Sprite som d�d
	virtual void kill() = 0;
	// M�ste deklareras i subklasser, anv�nds av motorn f�r att kolla om spriten har d�tt (skall f�rsvinna)
	virtual const bool isDead() const = 0; 
	// M�ste deklareras i subklasser, skall returnera true om spriten �r en fiende
	virtual const bool isHostile() const = 0; 

	// Funktion f�r sprite att beg�ra game over
	void gameOver(bool gameOver) const;

	// Funktioner f�r att fr�mst generera laser-skott
	void setGeneratedSprite(Sprite* newSprite) { generatedSprite = newSprite; }
	Sprite* getGeneratedSprite() const { return generatedSprite; }
	void nullifyGeneratedSprite() { generatedSprite = nullptr; }
	

protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // x,y = startposition i spelet. w,h = storleken p� bildk�llan. speed = hastighet f�r spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor f�rbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator f�rbjuden

	Sprite* generatedSprite;

	SDL_Texture* objTexture; //Spritens texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect �r storleken i filen. destRect representarar bilden i spelet

	int speed; // Hastighet som spriten r�r sig

	int xpos; // x-Position f�r spriten
	int ypos; // y-Position f�r spriten

};

#endif
