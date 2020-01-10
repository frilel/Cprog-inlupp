/*
Spelarens karaktär. Ska kunnas överskuggas av tillämpningen!?.
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

	Player(const Player&) = delete; // Copy-konstruktor förbjuden
	const Player& operator=(const Player&) = delete; // Tilldelningsoperator förbjuden

};

#endif