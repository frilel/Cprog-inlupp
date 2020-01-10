#include "Session.h"
#include <SDL.h>


Session::~Session()
{
	delete gameEngine;
}

void Session::run() { // initieras i main. Vi kan ta med parametrar senare tex "namn p� spel", "fullscreen", "FPS" osv.

	

	const int FPS = 60; // Om vi vill �ndra FPS
	const int frameDelay = 1000 / FPS; // Tiden f�r en sekund, i millisekunder, delat p� s� m�nga frames vi vill k�ra
	Uint32 frameStart;  // OBS! Enligt SDL: K�rs programmet i mer �n runt 49 dagar blir talet f�r stort f�r Uint32 och kraschar
	int frameTime;

	gameEngine = new GameEngine();
	gameEngine->init("Starlord", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (gameEngine->running()) { // allt detta vill vi l�gga i en klass "session"...

		frameStart = SDL_GetTicks(); //Returnerar tiden f�r n�r programmet startade, i millisekunder. frameStart blir tiden d� aktuella framen startar
		//gameEngine->handleEvents();
		gameEngine->update();
		gameEngine->render();

		frameTime = SDL_GetTicks() - frameStart;  //tiden att k�ra en hel frame = skillnaden mellan GetTicks fr�n b�rjan av loopen och denna andra GetTicks i slutet av loopen

		if (frameDelay > frameTime) { //om tiden att k�ra en frame �r mindre �n tiden vi vill att det ska ta att k�ra en frame:
			SDL_Delay(frameDelay - frameTime); // V�nta ut tiden till n�sta frame, loop, ska b�rja
		}
	}

	gameEngine->clean();
}
	/* 
	H�ndelser hanteras
	Sprites l�ggs till.
	Sprites tas bort.
	Rendering till spelf�nster.
	*/
	/*for (Component* c : added)
				comps.push_back(c);
			added.clear(); //alla element i vectorn rensas, pekarna.

			for (Component* c : removed) {
				for (std::vector<Component*>::iterator i = comps.begin(); i != comps.end(); ) //iterator f�r att ta bort components.  auto hade kunnats anv�ndas
					if (*i == c) {
						i = comps.erase(i); //tar bort fr�n vectorn
						delete c;
					}
					else
						i++; //om vi inte tar bort; hoppa fram
			}
			removed.clear();

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Component* c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

		} //yttre while
	}*/


	/*void Session::add(Component* c) {
		added.push_back(c);
	}*/

	/*void Session::remove(Component* c) {
		removed.push_back(c);
	}*/