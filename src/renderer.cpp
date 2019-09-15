#include "renderer.h"
//#include <string>
#include "graphics.h"
#include "audio.h"

//DRAW.C



Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Space Impact", SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, screen_width,
                                    screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }


    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }


    
    Graphics::instance().init(sdl_renderer);

    background = Graphics::instance().getBackGroundSprite();

    // //Add text
    blit(Graphics::instance().addTittle("Capstone Space"), 380, 150);
    blit(Graphics::instance().addText("Hit Enter"), 570, 250);

}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
//   TTF_Quit();
//   IMG_Quit();
//   Mix_Quit();
    SDL_Quit();

}

void Renderer::Render(Player &player, Bullet &bullet, Enemy &enemy) {
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen prepareScene
    SDL_SetRenderDrawColor(sdl_renderer, 96, 128, 255, 255);
    SDL_RenderClear(sdl_renderer);

    //Add Background
    int x;
    SDL_Rect dest;
    // for (x = 0 ; x < screen_width ; x += screen_width)
    // {
        dest.x = 0;//x;
        dest.y = 0;
        dest.w = screen_width;
        dest.h = screen_height;
        
    SDL_RenderCopy(sdl_renderer,  background, NULL, &dest);


    //Collision detection
    int cplayer = collision(player.currentX(), player.currentY(), grid_width, grid_height, enemy.currentX(), enemy.currentY(), grid_width, grid_height);
    int cbullet = collision(bullet.currentX(), bullet.currentY(), grid_width, grid_height, enemy.currentX(), enemy.currentY(), grid_width, grid_height);

    if (cbullet > 0){
        enemy.addTexture(Graphics::instance().getExplosionSprite());
        Audio::instance().playExplosion();
        enemy.setStatus(false);
        player.score += 1;
        cbullet = 0;
    }

    if (cplayer > 0 ){
        enemy.win = true;
        Audio::instance().stopMusic();
        Audio::instance().playGameOver();
    }

    if (enemy.win){
        player.addTexture(Graphics::instance().getExplosionSprite());
        blit(Graphics::instance().addTittle("Game Over"), 450, 150);
        frAnimation += 1;
        if (frAnimation > 50) {
            player.addTexture(nullptr);
            enemy.win = false;
            frAnimation = 0;
            
        }
    }


    //Add Objects
    blit(player.getTexture(), player.currentX(), player.currentY());

    if (bullet.currentStatus()){
        blit(bullet.getTexture(), bullet.currentX(), bullet.currentY());
    } else {
        bullet.moveTo(player.currentX(), player.currentY());
    }
    
    blit(enemy.getTexture(), enemy.currentX(), enemy.currentY());



    //Add Score
    blit(Graphics::instance().addText("Player: " + std::to_string(player.score)), 20, 20);
    blit(Graphics::instance().addText("Alien: " + std::to_string(enemy.score)), 1100, 20);


    //std::cout<<"bullet " << std::to_string(cbullet)<<"\n";

}


void Renderer::blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;
	
	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(sdl_renderer, texture, NULL, &dest);
    SDL_RenderPresent(sdl_renderer);
}

int Renderer::collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (MAX(x1, x2) < MIN(x1 + w1, x2 + w2)) && (MAX(y1, y2) < MIN(y1 + h1, y2 + h2));
}
