#include "Sprite.h"
#include "TextureManager.h"


Sprite::Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed){
	
	objTexture = TextureManager::LoadTexture(filenamePath); //Texture skapas och sparas i objTexture, används av render()

	//initialisera hastigheten
	speed = moveSpeed;

	// startpositionen
	xpos = x; 
	ypos = y;

	//Storleken på rect i bildkällan
	srcRect.w = w; 
	srcRect.h = h;

	//Placering av rect i bildkällan börjar 0,0 uppe i vänster
	srcRect.x = 0; 
	srcRect.y = 0;

	// storleken på rect i programmet blir lika stor som i bildkällan
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h;
	
}


void Sprite::update(GameEngine* gameEngine) { // rörelse och händelser sker här! TA EMOT GameEngine OCH KOLLA KOLLISION MED WINDOW OCH ANDRA SPRITES
	
	// Spriten rör på sig enligt xpos, ypos
	destRect.x = xpos; 
	destRect.y = ypos;

}

void Sprite::render() { // Draw...
	
	if (SDL_RenderCopy(GameEngine::renderer, objTexture, &srcRect, &destRect) != 0)
		std::cout << "Failed to render objTexture in Sprite: " << SDL_GetError() << std::endl;

}

