#ifndef PLAYER_H
#define PLAYER_H

#include "MovableSprite.h"

/*
Till�mparens subklass till MovableSprite.
Spelarens karakt�r.
*/


class Player : public MovableSprite
{

public:
	~Player();

	static Player* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till player-objekt

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites);
	
	/* H�ndelsehanteringar */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&);
	virtual void keyDown(const SDL_Event&);

	// Denna Sprite �r inte en fiende
	const bool isHostile() const { return false; }

	const bool isPlayer() const { return true; }
	
	// Min skjutfunktion som anropas varje Spacebar tryck
	virtual void shoot(); 


protected:

	Player(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : MovableSprite(filenamePath, x, y, w, h, moveSpeed) {}

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Player(const Player&) = delete; // Copy-konstruktor f�rbjuden
	const Player& operator=(const Player&) = delete; // Tilldelningsoperator f�rbjuden
	

};

#endif