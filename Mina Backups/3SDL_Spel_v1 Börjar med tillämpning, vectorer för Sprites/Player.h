/*
Spelarens karakt�r. Ska kunnas �verskuggas av till�mpningen!?.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"


class Player : public Sprite
{

public:

	~Player() { SDL_DestroyTexture(getTexture()); }
	static Player* getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed); // skickar pekare till player-objekt

	virtual void update(GameEngine*);
	
	virtual void keyDown(const SDL_Event&);
	
	//virtual void shoot() {} // Anropas varje Space tryck


protected:

	Player(const char* filenamePath, int x, int y, int w, int h, int moveSpeed) : Sprite(filenamePath, x, y, w, h, moveSpeed) {}

private:

	Player(const Player&) = delete; // Copy-konstruktor f�rbjuden
	const Player& operator=(const Player&) = delete; // Tilldelningsoperator f�rbjuden

};

#endif