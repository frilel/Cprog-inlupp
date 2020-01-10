#include "Session.h"
#include <SDL.h>


Session::~Session()
{
	delete gameEngine;
}

void Session::run() { // initieras i main. Vi kan ta med parametrar senare tex "namn på spel", "fullscreen", "FPS" osv.

	

	const int FPS = 60; // Om vi vill ändra FPS
	const int frameDelay = 1000 / FPS; // Tiden för en sekund, i millisekunder, delat på så många frames vi vill köra
	Uint32 frameStart;  // OBS! Enligt SDL: Körs programmet i mer än runt 49 dagar blir talet för stort för Uint32 och kraschar
	int frameTime;

	gameEngine = new GameEngine();
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
}
	/* 
	Händelser hanteras
	Sprites läggs till.
	Sprites tas bort.
	Rendering till spelfönster.
	*/
	/*for (Component* c : added)
				comps.push_back(c);
			added.clear(); //alla element i vectorn rensas, pekarna.

			for (Component* c : removed) {
				for (std::vector<Component*>::iterator i = comps.begin(); i != comps.end(); ) //iterator för att ta bort components.  auto hade kunnats användas
					if (*i == c) {
						i = comps.erase(i); //tar bort från vectorn
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