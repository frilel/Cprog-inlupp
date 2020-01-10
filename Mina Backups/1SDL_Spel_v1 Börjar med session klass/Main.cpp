/*Detta representerar spelets instans/session*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "GameEngine.h"

GameEngine* gameEngine = nullptr; // läggs "dynamiskt?", rensas när main är klar

int main(int argc, char** argv) {
	/*while(game is running) lite pseudokod
	{
		handle any user input
		update all object eg. postition etc.
		render changes to the display
	}*/
	const int FPS = 60;
	const int frameDelay = 1000 / FPS; // Tiden för en sekund delat på 60 frames, i millisekunder
	Uint32 frameStart;
	int frameTime;

	gameEngine = new GameEngine(); // skapas på stacken/heapen, och rensas när main avslutar?(nej kolla kommentar nedan)

/*Thank you for your videos ^^ 
Say, i'm pretty new to C++, but i was wondering, we are using several times some "new", but never some "delete", doesn't it create memory leaks ?

yes it does create memory leaks, whenever you use "new" go to the clean function in the game class and delete whatever you created.

It will, for now. I imagine at some point we'll be putting together linked lists to track each of those elements through,
then shoot those lists through a delete loop in their respective destructors. (I haven't reached that video yet. :-P) */

	gameEngine->init("Starlord", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (gameEngine->running()) { // allt detta vill vi lägga i en klass "session"...

		frameStart = SDL_GetTicks(); //Returnerar tiden för när programmet startade, i millisekunder. frameStart blir tiden då aktuella framen startar
		//gameEngine->handleEvents();
		gameEngine->update();
		gameEngine->render();

		frameTime = SDL_GetTicks() - frameStart;  //tiden att köra en hel frame = skillnaden mellan GetTicks från början av loopen och denna andra GetTicks i slutet av loopen

		if (frameDelay > frameTime) { //om tiden att köra en frame är mindre än tiden vi vill att det ska ta att köra en frame:
			SDL_Delay(frameDelay - frameTime); // Vänta ut tiden till nästa frame, loop, ska börja
		}
	}

	gameEngine->clean();

	return 0;
}