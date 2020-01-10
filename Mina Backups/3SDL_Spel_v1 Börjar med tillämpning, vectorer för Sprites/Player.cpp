#include "Player.h"





Player* Player::getInstance(const char* filenamePath, int x, int y, int w, int h, int moveSpeed)
{
	return new Player(filenamePath, x, y, w, h, moveSpeed);
}

void Player::update(GameEngine* gameEngine) { // r�relse sker h�r! I FRAMTIDEN H�NDELSER, KOLLA KOLLISION MED ANDRA SPRITES
	
	// Om player r�r sig utanf�r f�nstret V�NSTER
	if (getXpos() < 0) 
		getXpos() += getSpeed();
	// Om player r�r sig utanf�r f�nstret H�GER
	if ((getXpos() + getDestRect().w) > gameEngine->getWindowWidth())
		getXpos() -= getSpeed();
	// Om player r�r sig utanf�r f�nstret UPPTILL
	if (getYpos() < 0)
		getYpos() += getSpeed();
	// Om player r�r sig utanf�r f�nstret NEDTILL
	if((getYpos() + getDestRect().h) > gameEngine->getWindowHeight())
		getYpos() -= getSpeed();

	// Player r�r p� sig enligt xpos, ypos
	getDestRect().x = getXpos();
	//std::cout << "Player xpos: " << getDestRect().x << std::endl;
	getDestRect().y = getYpos();
	//std::cout << "Player ypos: " << getDestRect().y << std::endl;
			
}

void Player::keyDown(const SDL_Event& event) {
	switch (event.key.keysym.sym) {
	case SDLK_w: move(0, -getSpeed()); break;
	case SDLK_s: move(0, getSpeed()); break;
	case SDLK_a: move(-getSpeed(), 0); break;
	case SDLK_d: move(getSpeed(), 0); break;
		//shoot case
	}
}

