/*Detta representerar spelets instans/session*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "Session.h"


Session session;

int main(int argc, char** argv) {

	
	session.run();

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