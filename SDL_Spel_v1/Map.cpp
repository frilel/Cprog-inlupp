#include "Map.h"
#include "SDL_System.h"
#include <iostream>

int level1[20][25] = {
	{ 0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,1,1,1,0,0,2 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2 },
	{ 0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2 },
	{ 0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};

Map::Map() {
	black = SDLsystem.LoadTexture("assets/mapTiles/black.png");
	blue = SDLsystem.LoadTexture("assets/mapTiles/blue.png");
	purple = SDLsystem.LoadTexture("assets/mapTiles/purple.png");

	LoadMap(level1);

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = 32;
	srcRect.h =	destRect.h = 32;

	destRect.x = destRect.y = 0;
}

Map::~Map() {
	SDL_DestroyTexture(black);
	SDL_DestroyTexture(blue);
	SDL_DestroyTexture(purple);
	std::cout << "Map deconstructed..." << std::endl;
}

void Map::LoadMap(int arr[20][25]) { // Den skickade mapen kopieras över till vår faktiska map-array
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {

	int type = 0;

	for (int row = 0; row < 20; row++) { // går igenom varje rad - x
		for (int column = 0; column < 25; column++) { // går igenom varje kolumn - y
			type = map[row][column]; // varje index i arrayen kopieras till type, vi kollar sedan vilken typ av tile, siffra, som skall användas

			destRect.x = column * 32; // nästa position i x-led för tilen
			destRect.y = row * 32; // nästa position y-led för tilen

			switch (type) {
			case 0:
				SDLsystem.Draw(blue, srcRect, destRect);
				break;
			case 1:
				SDLsystem.Draw(black, srcRect, destRect);
				break;
			case 2:
				SDLsystem.Draw(purple, srcRect, destRect);
				break;
			default:
				break;
			}
		}
	}
}