/*Detta representerar sj�lva motorn*/

#include "GameEngine.h"
#include "SDL_System.h"
#include <iostream>

#include "Map.h"
//#include "Sprite.h"
//#include "Player.h"
//#include "Enemy.h"


//Sprite* player;
//Enemy* enemy;

Map* map;

//SDL_Renderer* GameEngine::renderer = nullptr;


GameEngine::~GameEngine()
{

}

void GameEngine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	windowWidth = width;
	windowHeight = height;
	if (SDLsystem.initSDL(title, xpos, ypos, width, height, fullscreen) == false)
		isRunning = false; // Om initiering av SDL gick snett s� startar inte spelloopen

	map = new Map();
	std::cout << "Map created!" << std::endl;
}

void GameEngine::run(int fps){

	const int FPS = fps; // Vald frames per second
	const int frameDelay = 1000 / FPS; // Tiden f�r en sekund, i millisekunder, delat p� s� m�nga frames vi vill k�ra
	Uint32 frameStart;  // OBS! Enligt SDL: K�rs programmet i mer �n runt 49 dagar blir talet f�r stort f�r Uint32 och kan krascha
	int frameTime;
	

	while (isRunning) { // motorn k�rs tills game over eller quit
		frameStart = SDL_GetTicks(); //Returnerar tiden f�r n�r programmet startade, i millisekunder. frameStart blir tiden d� aktuella framen startar

		updateSprites();

		handleEvents(activeSprites);
		update(activeSprites);
		render(activeSprites);

		frameTime = SDL_GetTicks() - frameStart;  //tiden att k�ra en hel frame = skillnaden mellan denna GetTicks i slutet av loopen och GetTicks fr�n b�rjan av loopen
		if (frameDelay > frameTime) { //om tiden att k�ra en frame �r mindre �n tiden vi vill att det ska ta att k�ra en frame:
			SDL_Delay(frameDelay - frameTime); // V�nta ut tiden till n�sta frame, loop, ska b�rja
		}
	} // motor k�rs
	std::cout << "isRunning stopped!..." << std::endl;
	clean();

}//run

void GameEngine::handleEvents(std::vector<Sprite*> &sprites){ // hantera event
	//std::cout << "Starting handleEvents!" << std::endl;
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			for (Sprite* s : sprites) //g�r igenom alla components och anropar deras event
				s->mouseDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			for (Sprite* s : sprites)
				s->mouseUp(event);
			break;
		case SDL_KEYDOWN:
			for (Sprite* s : sprites)
				s->keyDown(event);
			break;
		case SDL_KEYUP:
			for (Sprite* s : sprites)
				s->keyUp(event);
			break;
		default:
			break;
		} // switch
	} // while
}

void GameEngine::update(std::vector<Sprite*> &sprites){

	for (Sprite* s : sprites) {
		s->update(windowWidth, windowHeight, sprites);

		// Denna if-sats kollar om en laser har skjutits
		if (s->getGeneratedSprite() != nullptr) {
			std::cout << "Firing laser!" << std::endl;
			add(s->getGeneratedSprite());
			s->nullifyGeneratedSprite();
		}

		if (s->isDead()) { // sprites som har markerats som d�da tas bort
			std::cout << "Removing dead Sprite!" << std::endl;
			remove(s);
		}
	}

	// kolla om SDLsystem meddelar game over:
	if (SDLsystem.isItGameOver())
		isRunning = false;

}

void GameEngine::render(std::vector<Sprite*> &sprites) { //here we add stuff to the renderer:

	SDL_RenderClear(SDLsystem.getRenderer());
	
	map->DrawMap(); // nuvarande on�digt att ha h�r. Beh�ver inte updateras varje tick...
	
	for (Sprite* s : sprites) {
		s->render();
	}

	SDL_RenderPresent(SDLsystem.getRenderer());

}

void GameEngine::clean(){
	std::cout << "Cleaning Game Engine..." << std::endl;

	// S�kerst�ller att inga objekt finns kvar i vectorerna
	for (Sprite* s : addedSprites)
		delete s;
	addedSprites.clear();
	std::cout << "addedSprites cleared" << std::endl;

	for (Sprite* s : removedSprites)
		delete s;
	removedSprites.clear();
	std::cout << "removedSprites cleared" << std::endl;

	for (Sprite* s : activeSprites)
		delete s;
	activeSprites.clear();
	std::cout << "activeSprites cleared" << std::endl;

	delete map;
	std::cout << "Map deleted" << std::endl;

	SDLsystem.clean();
	std::cout << "Game Engine cleaned! In GameEngine clean()" << std::endl;
}

void GameEngine::add(Sprite* s) {
	addedSprites.push_back(s);
}

void GameEngine::remove(Sprite* s) {
	removedSprites.push_back(s);
}

void GameEngine::updateSprites() {
	for (Sprite* s : addedSprites)  // Added sprites l�ggs till i Active sprites
		activeSprites.push_back(s);
	addedSprites.clear(); // alla element i vectorn addedSprites som nu flyttats till activeSprites rensas

	for (Sprite* s : removedSprites) {
		for (std::vector<Sprite*>::iterator i = activeSprites.begin(); i != activeSprites.end(); ) { //iterator f�r att ta bort sprites.  auto hade kunnats anv�ndas
			if (*i == s) { // om Removed sprite finns i Active sprite s� tar den bort
				std::cout << "Erasing removed sprite from active list..." << std::endl;
				i = activeSprites.erase(i); //tar bort fr�n vectorn
				delete s;
			}
			else
				i++; //om vi inte tar bort; hoppa fram
		}
	}
	removedSprites.clear();  // alla element i vecorn rensas
}


