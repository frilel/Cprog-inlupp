#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

#include <vector>
#include "Sprite.h"


//class Sprite;
class GameEngine {

public:
	GameEngine() : isRunning(true), windowWidth(0), windowHeight(0) {};
	~GameEngine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void run();
	void clean();

	void handleEvents( std::vector<Sprite*> &activeSprites);
	void update( std::vector<Sprite*> & activeSprites);
	void render( std::vector<Sprite*> & activeSprites);
	
	const int& getWindowWidth() const { return windowWidth; }
	const int& getWindowHeight() const { return windowHeight; }

	void add(Sprite*);
	void remove(Sprite*);

	std::vector<Sprite*>& getActiveSprites() { return activeSprites; }

	void updateSprites();

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	GameEngine(const GameEngine&) = delete; // Copy-konstruktor f�rbjuden
	const GameEngine& operator=(const GameEngine&) = delete; // Tilldelningsoperator f�rbjuden
	
	bool isRunning;  // Game is running
	
	int windowWidth;
	int windowHeight;
	
	/*under g�ng l�ggs saker in i added och i slutet av loppen flyttas allt
	till vectorn activeSprites, eftersom att l�gga till saker samtidigt som vectorn kanske anv�nds ger problem.*/
	std::vector<Sprite*> activeSprites;
	std::vector<Sprite*> addedSprites, removedSprites; 

};

#endif GAME_H