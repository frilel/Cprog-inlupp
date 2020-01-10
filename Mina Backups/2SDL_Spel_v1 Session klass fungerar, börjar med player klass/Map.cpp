#include "Map.h"
#include "TextureManager.h"

int level1[20][25] = {
	{ 0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};

Map::Map() {
	black = TextureManager::LoadTexture("assets/mapTiles/black.png");
	blue = TextureManager::LoadTexture("assets/mapTiles/blue.png");
	purple = TextureManager::LoadTexture("assets/mapTiles/purple.png");

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
}

void Map::LoadMap(int arr[20][25]) { // Den skickade mapen kopieras �ver till v�r faktiska map-array
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {

	int type = 0;

	for (int row = 0; row < 20; row++) { // g�r igenom varje rad - x
		for (int column = 0; column < 25; column++) { // g�r igenom varje kolumn - y
			type = map[row][column]; // varje index i arrayen kopieras till type, vi kollar sedan vilken typ av tile, siffra, som skall anv�ndas

			destRect.x = column * 32; // n�sta position i x-led f�r tilen
			destRect.y = row * 32; // n�sta position y-led f�r tilen

			switch (type) {
			case 0:
				TextureManager::Draw(blue, srcRect, destRect);
				break;
			case 1:
				TextureManager::Draw(black, srcRect, destRect);
				break;
			case 2:
				TextureManager::Draw(purple, srcRect, destRect);
				break;
			default:
				break;
			}
		}
	}
}