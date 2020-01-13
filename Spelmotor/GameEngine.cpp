/*Detta representerar själva motorn*/

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
		isRunning = false; // Om initiering av SDL gick snett så startar inte spelloopen

	map = new Map();
	std::cout << "Map created!" << std::endl;
}

void GameEngine::run(int fps){

	const int FPS = fps; // Vald frames per second
	const int frameDelay = 1000 / FPS; // Tiden för en sekund, i millisekunder, delat på så många frames vi vill köra
	Uint32 frameStart;  // OBS! Enligt SDL: Körs programmet i mer än runt 49 dagar blir talet för stort för Uint32 och kan krascha
	int frameTime;
	

	while (isRunning) { // motorn körs tills game over eller quit
		frameStart = SDL_GetTicks(); //Returnerar tiden för när programmet startade, i millisekunder. frameStart blir tiden då aktuella framen startar

		updateSprites();

		handleEvents(activeSprites);
		update(activeSprites);
		render(activeSprites);

		frameTime = SDL_GetTicks() - frameStart;  //tiden att köra en hel frame = skillnaden mellan denna GetTicks i slutet av loopen och GetTicks från början av loopen
		if (frameDelay > frameTime) { //om tiden att köra en frame är mindre än tiden vi vill att det ska ta att köra en frame:
			SDL_Delay(frameDelay - frameTime); // Vänta ut tiden till nästa frame, loop, ska börja
		}
	} // motor körs
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
			for (Sprite* s : sprites) //går igenom alla components och anropar deras event
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

		if (s->isDead()) { // sprites som har markerats som döda tas bort
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
	
	map->DrawMap(); // nuvarande onödigt att ha här. Behöver inte updateras varje tick...
	
	for (Sprite* s : sprites) {
		s->render();
	}

	SDL_RenderPresent(SDLsystem.getRenderer());

}

void GameEngine::clean(){
	std::cout << "Cleaning Game Engine..." << std::endl;

	// Säkerställer att inga objekt finns kvar i vectorerna
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
	for (Sprite* s : addedSprites)  // Added sprites läggs till i Active sprites
		activeSprites.push_back(s);
	addedSprites.clear(); // alla element i vectorn addedSprites som nu flyttats till activeSprites rensas

	for (Sprite* s : removedSprites) {
		for (std::vector<Sprite*>::iterator i = activeSprites.begin(); i != activeSprites.end(); ) { //iterator för att ta bort sprites.  auto hade kunnats användas
			if (*i == s) { // om Removed sprite finns i Active sprite så tar den bort
				std::cout << "Erasing removed sprite from active list..." << std::endl;
				i = activeSprites.erase(i); //tar bort från vectorn
				delete s;
			}
			else
				i++; //om vi inte tar bort; hoppa fram
		}
	}
	removedSprites.clear();  // alla element i vecorn rensas
}


