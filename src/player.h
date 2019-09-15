#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "entity.h"
#include "graphics.h"

class Player {
    public:
        enum class Direction { kUp, kDown, kLeft, kRight, kNone };

        Player(int screen_width, int screen_height, int grid_width, int grid_height)
            : screen_width(screen_width),
                screen_height(screen_height),
                grid_width(grid_width),
                grid_height(grid_height) 
                { player.moveTo(grid_width, (screen_height-grid_height/2)/2 ); 
                player.addTexture(Graphics::instance().getPlayerSprite());
                }

        void Update();


        bool hit_enter{false};

        Direction direction = Direction::kNone;

        int score{0};

        int currentY(){ return player.currentY();}
        int currentX(){ return player.currentX();}
        SDL_Texture* getTexture(){ return player.getTexture(); }
        void moveTo(int x, int y){player.moveTo(x, y);}
        void addTexture(SDL_Texture *texture) { player.addTexture(texture); }

    private:
        int screen_width;
        int screen_height;
        int grid_width;
        int grid_height;
        Entity player;

};

#endif