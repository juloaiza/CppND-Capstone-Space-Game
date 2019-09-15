#include "graphics.h"


void Graphics::init(SDL_Renderer* _sdl_renderer){


    sdl_renderer = _sdl_renderer;

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    //Add Sprites
    gBackGround = loadTexture("res/textures/galaxy2.jpg");	
    gPlayer = loadTexture("res/textures/player.png");
    gBullet = loadTexture("res/textures/playerBullet.png");
    gEnemy =loadTexture("res/textures/enemy.png");

    gExplosion = loadTexture("res/textures/explosion.png");

    TTF_Init();
    if (TTF_Init() == -1) {
        std::cerr << "TTF could not be created" << TTF_GetError() << "\n";
    }

    //Open the font
    gFontTittle = TTF_OpenFont( "res/textures/Sansation-Bold.ttf", 70 );
    gFontText = TTF_OpenFont( "res/textures/Sansation-Regular.ttf", 35 );

}




//Load Texture
SDL_Texture* Graphics::loadTexture(const char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(sdl_renderer, filename);
    if ( texture == nullptr )
  {
      std::cout << "Failed to load texture " << filename << " error : " << SDL_GetError() << std::endl;
      return nullptr;
  }

	return texture;
}



//Add Text
SDL_Texture* Graphics::createTextTexture(TTF_Font* font, std::string text)
{
	SDL_Texture *texture;

	//SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", "Text");

  //Render the text onto a surface using the provided font and color
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {255,255,255});
  //Handling font rendering errors
  if(surface == NULL) {

    printf("Text Render Error: %s\n", TTF_GetError());
    return NULL;
  }

	texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
    if ( texture == nullptr )
  {
      std::cout << "Text Texture Creation Error : " << SDL_GetError() << std::endl;
      return nullptr;
  }

	return texture;

}


SDL_Texture* Graphics::addText(std::string text){
    return createTextTexture(gFontText, text);
}


SDL_Texture* Graphics::addTittle(std::string text){
     return createTextTexture(gFontTittle, text);
}
