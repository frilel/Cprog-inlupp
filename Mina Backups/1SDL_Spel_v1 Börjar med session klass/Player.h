/*#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
class Player : public Sprite
{

public:
    static Player* getInstance(const char* filenamePath, int x, int y, int w, int h);
	void update();
	void render();
	virtual void keyDown(const SDL_Event&);
	void perform();

protected:
	Player(const char* filenamePath, int x, int y, int w, int h);

};

#endif/*