#include "Player.h"
#include <iostream>
#include "SDL_System.h"
#include "Laser.h"


Player::~Player() {

	gameOver(true);
	std::cout << "Player destructor: Game Over" << std::endl;
	
}

Player* Player::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Player(filenamePath, x, y, w, h, moveSpeed);
}

void Player::update(int winW, int winH, std::vector<Sprite*> &activeSprites) { // rörelse sker här! I FRAMTIDEN HÄNDELSER, KOLLA KOLLISION MED ANDRA SPRITES ?
	//std::cout << "Player updated Player.cpp!" << std::endl;

	// Om player rör sig utanför fönstret VÄNSTER
	if (getXpos() < 0) 
		move(getSpeed(), 0); // Hindra player att fortsätta åt vänster

	// Om player rör sig utanför fönstret HÖGER
	if ((getXpos() + getDestRect().w) > winW)
		move(-getSpeed(), 0);  // Hindra player att fortsätta åt höger

	// Om player rör sig utanför fönstret UPPTILL
	if (getYpos() < 0) 
		move(0, getSpeed());
	
	// Om player rör sig utanför fönstret NEDTILL
	if((getYpos() + getDestRect().h) > winH)
		move(0, -getSpeed());

	// Player rör på sig enligt xpos, ypos
	getDestRect().x = getXpos();
	getDestRect().y = getYpos();

	imDead = collisionTest(activeSprites); // returnerar true om player har kolliderat med någon annan Sprite
		
			
}

void Player::keyDown(const SDL_Event& event) {
	//std::cout << "Player event in Player.cpp!" << std::endl;
	switch (event.key.keysym.sym) {
	case SDLK_w: move(0, -getSpeed()); break;
	case SDLK_s: move(0, getSpeed()); break;
	case SDLK_a: move(-getSpeed(), 0); break;
	case SDLK_d: move(getSpeed(), 0); break;
	case SDLK_SPACE: shoot(); break;
	}
}

void Player::shoot() {
	Laser* laser = Laser::getInstance("assets/weapons/laserBlue01.png", getDestRect().x+(getDestRect().w/2), getDestRect().y-23, 5, 21, 10);
	setGeneratedSprite(laser);
}
