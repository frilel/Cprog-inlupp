/*Detta representerar själva motorn*/

#include "GameEngine.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Map.h"

Sprite* player;
//Sprite* enemy;

Map* map;

SDL_Renderer* GameEngine::renderer = nullptr;

GameEngine::GameEngine()
{}
GameEngine::~GameEngine()
{
	//Mix_CloseAudio();
	//Mix_Quit();
	//TTF_CloseFont(font);
	//TTF_Quit();
	delete player;
	delete map;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void GameEngine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window == NULL) {
				printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
				isRunning = false;
			}else{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				isRunning = false;
			}else{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	} //initialize
	else {
		isRunning = false;
	}

	player = new Sprite("assets/characters/player.png", 0, 0, 42, 32);
	//enemy = new Sprite("assets/characters/enemy.png", 50, 50, 35, 32);
	map = new Map();

	/*SDL_Surface* tmpSurface = IMG_Load("c:/C++ saker/assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	std::cout << "playerTex loaded!" << std::endl;
	SDL_FreeSurface(tmpSurface);*/
}

void GameEngine::handleEvents(){ // används inte nu, allt läggs i update atm

}

void GameEngine::update(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		/*switch (event.key.keysym.sym) {
		case SDLK_UP: gubbRect.y--; break;
		case SDLK_DOWN: gubbRect.y++; break;
		case SDLK_LEFT: gubbRect.x--; break;
		case SDLK_RIGHT: gubbRect.x++; break;
		}*/
		player->update(event);
		break;
	case SDL_KEYUP:
		break;
	default:
		break;
	}
}

void GameEngine::render() {

	SDL_RenderClear(renderer);
	map->DrawMap();
	//here we add stuff to the renderer:
	player->render(); //i framtiden läggs alla objekt i en vector för iterering
	//enemy->render();
	SDL_RenderPresent(renderer); 
}

void GameEngine::clean(){
	//SDL_DestroyTexture(playerTex); // Behövs göras i GameObject nu, ej implementerat
	//Mix_CloseAudio();
	//Mix_Quit();
	//TTF_CloseFont(font);
	//TTF_Quit();
	delete player;
	delete map;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}


