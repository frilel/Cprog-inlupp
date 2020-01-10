#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <SDL_image.h>

class Map {
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Map(const Map&) = delete; // Copy-konstruktor f�rbjuden
	const Map& operator=(const Map&) = delete; // Tilldelningsoperator f�rbjuden

	SDL_Rect srcRect, destRect;
	SDL_Texture* black;
	SDL_Texture* blue;
	SDL_Texture* purple;

	int map[20][25];


};
#endif