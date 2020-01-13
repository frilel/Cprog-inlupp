#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

/*
Denna klass tillh�r den generella delen.
Detta �r en abstrakt klass �r f�r ImmovableSprite och MovableSprite. 
Inga objekt g�r att skapa utifr�n bara denna klass.
Till�mparen m�ste skapa egna subklasser av ImmovableSprite och MovableSprite f�r att till�mpningsprogrammet skall kunna skapa objekt.
*/


class Sprite {

public:

	virtual ~Sprite(); // Definierad virtual s� att subklasser kan addera sina egna saker som skall destrueras

	virtual void update(int winW, int winH, std::vector<Sprite*> &activeSprites) = 0; // Sprites "tick"-funktion. Till�mpningsprogrammeraren m�ste sj�lv deklarera denna.
	virtual void render(); // Om en subklass vill implementera animationer kan man beh�va �ndra denna...

	/* H�ndelsehanteringar vi l�ter subklasser deklarera */
	virtual void mouseDown(const SDL_Event&) {}
	virtual void mouseUp(const SDL_Event&) {}
	virtual void keyDown(const SDL_Event&) {}
	virtual void keyUp(const SDL_Event&) {}
	
	// Ange f�rflyttning i x-led och y-led. Adderar v�rdena till variablerna xpos och ypos
	//virtual void move(int x, int y) { xpos += x; ypos += y; }

	// Standard kollisions-test med alla aktiva sprite-objekt returnerar true om objektet har kolliderat med ett annat
	virtual bool collisionTest(std::vector<Sprite*>& activeSprites);

	// M�ste deklareras i subklasser, skall returnera true om spriten �r en fiende
	virtual const bool isHostile() const = 0;
	// Playerklassen kommer �ndra denna f�r att identifiera sig som Player
	virtual const bool isPlayer() const { return false; }

	// Anv�nds f�r att markera att en Sprite ska d�
	void kill() { imDead = true; };
	// Anv�nds av motorn f�r att kolla om spriten har d�tt (skall f�rsvinna)
	const bool isDead() const { return imDead; };

	// H�mtningar av icke-const SDL Objekt
	SDL_Rect& getSrcRect();
	SDL_Rect& getDestRect();
	SDL_Texture* getTexture() { return objTexture; }
	// H�mtningar av const SDL Objekt, kr�vs f�r SDL_HasIntersection() i kollisionsdetekteringen
	const SDL_Rect& getSrcRect() const { return srcRect; }
	const SDL_Rect& getDestRect() const { return destRect; }

	// Positioneringar som anv�nds av update() f�r att uppdatera spritens positioner i spelet
	int& getXpos() { return xpos; }
	int& getYpos() { return ypos; }

	// Hantering av Sprites hastighet
	//const int& getSpeed() const { return moveSpeed; }
	//virtual void setSpeed(int s) { moveSpeed = s; }
	
	// Funktion f�r Sprite att beg�ra game over till SDLsystem, som i sin tur ger informationen till GameEngine
	void gameOver(bool gameOver) const;

	// Funktioner f�r att Sprites skall kunna generera egna Sprites. F�r n�rvarande implementerat: laser-skott
	void setGeneratedSprite(Sprite* newSprite) { generatedSprite = newSprite; }
	Sprite* getGeneratedSprite() const { return generatedSprite; }
	void nullifyGeneratedSprite() { generatedSprite = nullptr; }
	

protected:
	Sprite(const char* filenamePath, int x, int y, int w, int h); // x,y = startposition i spelet. w,h = storleken p� bildk�llan. speed = hastighet f�r spriten.

private:
	/*Obs att copy-konstruktorer och tilldelningsoperatorer genereras automatiskt f�r alla klasser som inte deklarerar egna.
	Vissa anser d�rf�r att man alltid b�r deklarera en privat copy-konstruktor och en privat tilldelningsoperator f�r klasser i klass hierarki.*/
	Sprite(const Sprite&) = delete; // Copy-konstruktor f�rbjuden
	const Sprite& operator=(const Sprite&) = delete; // Tilldelningsoperator f�rbjuden
	Sprite() = delete; // Default-konstruktor f�rbjuden

	SDL_Texture* objTexture; //Sprites texture, bilden, skickas med till renderaren
	SDL_Rect srcRect, destRect; //srcRect �r storleken i filen. destRect representarar bilden i spelet

	int xpos; // x-Position f�r spriten
	int ypos; // y-Position f�r spriten
	//int moveSpeed; // Hastighet som spriten r�r sig

	bool imDead; // �r Spriten d�d eller levande

	Sprite* generatedSprite; // Sprite-pekare till Sprite-genererad Sprite
};

#endif
