#include "Sprite.h"
#include "TextureManager.h"


Sprite::Sprite(const char* filenamePath, int x, int y, int w, int h, int moveSpeed){
	
	objTexture = TextureManager::LoadTexture(filenamePath); //Texture skapas och sparas i objTexture, anv�nds av render()

	//initialisera hastigheten
	speed = moveSpeed;

	// startpositionen
	xpos = x; 
	ypos = y;

	//Storleken p� rect i bildk�llan
	srcRect.w = w; 
	srcRect.h = h;

	//Placering av rect i bildk�llan b�rjar 0,0 uppe i v�nster
	srcRect.x = 0; 
	srcRect.y = 0;

	// storleken p� rect i programmet blir lika stor som i bildk�llan
	destRect.w = srcRect.w; 
	destRect.h = srcRect.h;
	
}


void Sprite::update(GameEngine* gameEngine) { // r�relse och h�ndelser sker h�r! TA EMOT GameEngine OCH KOLLA KOLLISION MED WINDOW OCH ANDRA SPRITES
	
	// Spriten r�r p� sig enligt xpos, ypos
	destRect.x = xpos; 
	destRect.y = ypos;

}

void Sprite::render() { // Draw...
	
	if (SDL_RenderCopy(GameEngine::renderer, objTexture, &srcRect, &destRect) != 0)
		std::cout << "Failed to render objTexture in Sprite: " << SDL_GetError() << std::endl;

}

