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

Till�mpningen skall kunna:
 -V�lja hur banan skall se ut.
 -V�lja hur spelaren skall se ut.
 -V�lja hur fienden skall se ut.
 -V�lja hur m�nga fiender som skall genereras
	Dessa genereras automatiskt, max 10? �t g�ngen med varierande position och hastighet. (Man kan skicka med max hastighet, hastigheten g�r sedan fr�n 1 till max mellan varje fiende?)

N�r spelaren har undvikit alla fiender, som d�r n�r dem n�r botten, har man vunnit.

*/