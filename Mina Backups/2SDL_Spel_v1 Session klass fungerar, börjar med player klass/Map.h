#ifndef MAP_H
#define MAP_H
#include "GameEngine.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect srcRect, destRect;
	SDL_Texture* black;
	SDL_Texture* blue;
	SDL_Texture* purple;

	int map[20][25];


};
#endif