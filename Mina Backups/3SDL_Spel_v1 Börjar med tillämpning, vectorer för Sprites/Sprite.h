#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"


/*Denna klass är för Objekt i världen, som spelaren och fienden*/


class Sprite {

public:

	~Sprite() { SDL_DestroyTexture(objTexture); } // Inget mer som behövs tas bort? rect?

	virtual void update(GameEngine*);
	virtual void render();

	/* Alla sprites kan behöva agera på händelser*/
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

	virtual void move(int x, int y) { xpos += x; ypos += y; } // addera (x) till xpos och (y) till ypos. Enda sättet att flytta vår sprite efter instansiering
	
	
protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // x,y = startposition i spelet. w,h = storleken på bildkällan. speed = hastighet för spriten.

private:

	int speed;

	int xpos; // x-Position för spriten
	int ypos; // y-Position för spriten

	SDL_Texture* objTexture; //Spritens texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect är storleken i filen. destRect representarar bilden i spelet

	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor förbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator förbjuden
};

#endif
