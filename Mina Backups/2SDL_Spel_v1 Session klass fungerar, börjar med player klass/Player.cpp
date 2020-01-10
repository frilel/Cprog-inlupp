/*#include "Player.h"
#include "TextureManager.h"


namespace starlord {
	Player::Player(const char* filenamePath, int x, int y, int w, int h) : Sprite(filenamePath,x, y, w, h)
	{
		TextureManager::LoadTexture(const char* filenamePath)
	}

	Player::~Player()
	{

	}

	Player* Player::getInstance(const char* filenamePath, int x, int y, int w, int h)
	{
		return new Player(filenamePath, x, y, w, h);
	}

	void Player::update() const // render...
	{
		xpos++;
		ypos++;

		srcRect.x = 0;
		srcRect.y = 0;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = srcRect.w * 1; // 1 = ändra storlek
		destRect.h = srcRect.h * 1;
	}
	void Player::render() {

	}
}*/