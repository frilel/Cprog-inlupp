/*Vår instansiering av GameEnginge sker med Session.
Innehåller en datasamling, vector, med pekare till Components som skall synas på skärmen.
Den har i huvudsak två medlemsfunktioner: add() för att lägga till Components och
run() som innehåller en händelseloop, där vid tangent/mushändelse skall components motsvarande
funktioner anropas och göra det som skall hända. */

#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include "GameEngine.h"



class Session
	{
	public:
		//void add(Component* c);
		//void remove(Component* c);
		void run();
		~Session();
	private:
		GameEngine* gameEngine = nullptr;
		std::vector<Sprite*> comps;
		std::vector<Sprite*> added, removed; /*under gång läggs saker in i added och i slutet av loppen flyttas allt
		till vectorn comps, eftersom att lägga till saker samtidigt som vectorn kanske används ger problem.*/
};

#endif