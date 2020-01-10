/*Detta representerar spelets instans/session*/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include "Session.h"



int main(int argc, char** argv) {
	/*while(game is running) lite pseudokod
	{
		handle any user input
		update all object eg. postition etc.
		render changes to the display
	}*/
	Session session;

	session.run();

/*Thank you for your videos ^^ 
Say, i'm pretty new to C++, but i was wondering, we are using several times some "new", but never some "delete", doesn't it create memory leaks ?

yes it does create memory leaks, whenever you use "new" go to the clean function in the game class and delete whatever you created.

It will, for now. I imagine at some point we'll be putting together linked lists to track each of those elements through,
then shoot those lists through a delete loop in their respective destructors. (I haven't reached that video yet. :-P) */

	

	return 0;
}