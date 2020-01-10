#include "Session.h"
#include <SDL.h>
#include "GameEngine.h"

Session::~Session()
{
}

void Session::run() { // allt som skett i main sker här
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component* c : comps) //går igenom alla components och anropar deras event
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (Component* c : comps)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Component* c : comps)
						c->keyUp(eve);
					break;

				} // switch
			} // inre while

			for (Component* c : added)
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


	}


	/*void Session::add(Component* c) {
		added.push_back(c);
	}*/

	/*void Session::remove(Component* c) {
		removed.push_back(c);
	}*/