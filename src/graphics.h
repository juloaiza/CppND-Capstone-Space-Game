#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


//Singleton
class Graphics
{
public:
    static Graphics& instance()
    {
        static Graphics *instance = new Graphics();
        return *instance;
    }

    void init(SDL_Renderer* _sdl_renderer);

    SDL_Texture* addText(std::string text);
    SDL_Texture* addTittle(std::string text);

    SDL_Texture* getPlayerSprite() { return gPlayer;}
    SDL_Texture* getEnemySprite() { return gEnemy;}
    SDL_Texture* getBulletSprite() { return gBullet;}
    SDL_Texture* getBackGroundSprite() { return gBackGround;}
    SDL_Texture* getExplosionSprite() { return gExplosion;}


private:
    Graphics() {} //Private constructor

    SDL_Renderer* sdl_renderer;

    SDL_Texture* loadTexture(const char *filename); 
    SDL_Texture* createTextTexture(TTF_Font* font, std::string text);

    //Sprites
    SDL_Texture* gPlayer;
    SDL_Texture* gEnemy;
    SDL_Texture* gBullet;
    SDL_Texture* gBackGround; 
    SDL_Texture* gExplosion; 

    //Fonts
    TTF_Font* gFontTittle;
    TTF_Font* gFontText;
};






#endif