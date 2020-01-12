#ifndef PLAYER_H
#define PLAYER_H

#include "MovableSprite.h"

/*
Tillämparens subklass till MovableSprite.
Spelarens karaktär.
*/


class Player : public MovableSprite
{

public:
	~Player();

	static Player* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till player-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites);
	
	/* Händelsehanteringar */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&);
	virtual void keyDown(const SDL_Event&);

	// Denna Sprite är inte en fiende
	const bool isHostile() const { return false; }

	const bool isPlayer() const { return true; }
	
	// Min skjutfunktion som anropas varje Spacebar tryck
	virtual void shoot(); 


protected:

	Player(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : MovableSprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt för alla klasser som inte deklarerar egna.
	Vissa anser därför att man alltid bör deklarera en privat copy-konstruktor och en privat tilldelningsoperator för klasser i klass hierarki.*/
	Player(const Player&) = delete; // Copy-konstruktor förbjuden
	const Player& operator=(const Player&) = delete; // Tilldelningsoperator förbjuden
	

};

#endif