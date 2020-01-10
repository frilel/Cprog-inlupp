#ifndef SPRITE_H
#define SPRITE_H
/*Denna klass är för Objekt i världen, som spelaren och fienden*/
#include "GameEngine.h"

class Sprite {

public:
	
	Sprite(const char* filenamePath, int x, int y, int w, int h); // vill göra protected, getInstance() skall skapa object
	~Sprite();

	virtual void update(const SDL_Event& event);
	virtual void render();

	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}

	const SDL_Rect& getSrcRect() const { return srcRect; }
	const SDL_Rect& getDestRect() const { return destRect; }
	const SDL_Texture* getTexture() const { return objTexture; }

	const int& getXpos() const { return xpos; }
	const int& getYpos() const { return ypos; }
	void changeXpos(int x) { xpos = x; }
	void changeYpos(int y) { ypos = y; }

	
protected:

private:

	int xpos; // x-Position för spriten
	int ypos; // y-Position för spriten
	SDL_Texture* objTexture; //Spritens texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect är storleken i filen. destRect representarar bilden i spelet
	Sprite(const Sprite&) = delete; // Copy-konstruktor förbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator förbjuden
};

#endif
