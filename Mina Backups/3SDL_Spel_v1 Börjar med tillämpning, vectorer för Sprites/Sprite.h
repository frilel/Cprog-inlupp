#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"


/*Denna klass �r f�r Objekt i v�rlden, som spelaren och fienden*/


class Sprite {

public:

	~Sprite() { SDL_DestroyTexture(objTexture); } // Inget mer som beh�vs tas bort? rect?

	virtual void update(GameEngine*);
	virtual void render();

	/* Alla sprites kan beh�va agera p� h�ndelser*/
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}

	// SDL Objekt
	virtual SDL_Rect& getSrcRect() { return srcRect; }
	virtual SDL_Rect& getDestRect() { return destRect; }
	virtual SDL_Texture* getTexture() const { return objTexture; }

	//Positioneringar
	virtual int& getXpos() { return xpos; }
	virtual int& getYpos() { return ypos; }

	//Hastighet
	virtual int& getSpeed() { return speed; }

	virtual void move(int x, int y) { xpos += x; ypos += y; } // addera (x) till xpos och (y) till ypos. Enda s�ttet att flytta v�r sprite efter instansiering
	
	
protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // x,y = startposition i spelet. w,h = storleken p� bildk�llan. speed = hastighet f�r spriten.

private:

	int speed;

	int xpos; // x-Position f�r spriten
	int ypos; // y-Position f�r spriten

	SDL_Texture* objTexture; //Spritens texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect �r storleken i filen. destRect representarar bilden i spelet

	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor f�rbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator f�rbjuden
};

#endif
