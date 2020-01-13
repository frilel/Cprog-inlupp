/*Detta representerar spelets instans/session*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"

//TESTAR ATT ÄNDRA 2


int main(int argc, char** argv) {
	GameEngine gameEngine;
	gameEngine.init("Starlord", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	Player* player = Player::getInstance("assets/characters/player.png", 400, 600, 42, 32, 8);
	gameEngine.add(player);

	Enemy* enemy1 = Enemy::getInstance("assets/characters/enemy.png", 400, 100, 35, 32, 1);
	gameEngine.add(enemy1);



	gameEngine.run(60);

	return 0;
}
/*

Tillämpningen skall kunna:
 -Välja hur banan skall se ut.
 -Välja hur spelaren skall se ut.
 -Välja hur fienden skall se ut.
 -Välja hur många fiender som skall genereras
	Dessa genereras automatiskt, max 10? åt gången med varierande position och hastighet. (Man kan skicka med max hastighet, hastigheten går sedan från 1 till max mellan varje fiende?)

När spelaren har undvikit alla fiender, som dör när dem når botten, har man vunnit.

*/