/*V�r instansiering av GameEnginge sker med Session.
Inneh�ller en datasamling, vector, med pekare till Components som skall synas p� sk�rmen.
Den har i huvudsak tv� medlemsfunktioner: add() f�r att l�gga till Components och
run() som inneh�ller en h�ndelseloop, d�r vid tangent/mush�ndelse skall components motsvarande
funktioner anropas och g�ra det som skall h�nda. */

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
		std::vector<Sprite*> added, removed; /*under g�ng l�ggs saker in i added och i slutet av loppen flyttas allt
		till vectorn comps, eftersom att l�gga till saker samtidigt som vectorn kanske anv�nds ger problem.*/
};

#endif