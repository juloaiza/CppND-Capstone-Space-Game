#ifndef RENDERER_H
#define RENDERER_H

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <iostream>
#include <vector>
#include "SDL.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"


class Renderer {
    public:
        Renderer(const std::size_t screen_width, const std::size_t screen_height,
                const std::size_t grid_width, const std::size_t grid_height);
        ~Renderer();

        void UpdateWindowTitle(int score, int fps);
        void Render(Player &player, Bullet &bullet, Enemy &enemy);
        void blit(SDL_Texture *texture, int x, int y);
        
        int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

    private:
        SDL_Window *sdl_window;
        SDL_Renderer *sdl_renderer;

        SDL_Texture* background; 

        const std::size_t screen_width;
        const std::size_t screen_height;
        const std::size_t grid_width;
        const std::size_t grid_height;

        int frAnimation{0};
};

#endif