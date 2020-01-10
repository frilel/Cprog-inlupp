/*Detta representerar själva motorn*/

#include "GameEngine.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

Player* player;
Enemy* enemy;

Map* map;

SDL_Renderer* GameEngine::renderer = nullptr;


GameEngine::~GameEngine()
{
	/*//Mix_CloseAudio();
	//Mix_Quit();
	//TTF_CloseFont(font);
	//TTF_Quit();
	delete player;
	delete map;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned! In destruktor" << std::endl;*/
}

void GameEngine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	//Hämta vald storleken på window
	windowWidth = width;
	windowHeight = height;

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window == NULL) {
			std::cout << "Window could not be created! SDL Error: " << std::endl << SDL_GetError() << std::endl;
			isRunning = false;
		}
		else {
			std::cout << "Window created!" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
		}
				
		if (renderer == NULL) {
			std::cout << "Renderer could not be created! SDL Error: " << std::endl << SDL_GetError() << std::endl;
			isRunning = false;
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	} //initialize
	else {
		isRunning = false;
		std::cout << "SDL_Init failed! SDL Error: " << std::endl << SDL_GetError() << std::endl;
	}
	



	map = new Map();
	std::cout << "Map created!" << std::endl;

	player = Player::getInstance("assets/characters/player.png", width/2, height-32, 42, 32, 8);
	std::cout << "Player created!" << std::endl;
	enemy = Enemy::getInstance("assets/characters/enemy.png", width/2, 0, 35, 32, 1);
	std::cout << "Enemy created!" << std::endl;
	

	/*SDL_Surface* tmpSurface = IMG_Load("c:/C++ saker/assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	std::cout << "playerTex loaded!" << std::endl;
	SDL_FreeSurface(tmpSurface);*/
}

void GameEngine::handleEvents(){ // hantera event
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			player->keyDown(event);
			break;
		case SDL_KEYUP:
			break;
		default:
			break;
		}
	}
}

void GameEngine::update(GameEngine* gameEngine){
	player->update(gameEngine);

	enemy->update(gameEngine);

}

void GameEngine::render() {
	
	SDL_RenderClear(renderer);
	//here we add stuff to the renderer:

	map->DrawMap(); // nuvarande onödigt att ha här. Behöver inte updateras varje tick...
	player->render(); //i framtiden läggs alla objekt i en vector för iterering
	enemy->render();

	SDL_RenderPresent(renderer); 
}

void GameEngine::clean(){
	//SDL_DestroyTexture(playerTex); // Behövs göras i GameObject nu, ej implementerat
	//Mix_CloseAudio();
	//Mix_Quit();
	//TTF_CloseFont(font);
	//TTF_Quit();
	delete player;
	delete enemy;
	delete map;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}


