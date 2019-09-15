#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "SDL.h"
#include "entity.h"
#include "graphics.h"

class Enemy {
    public:
        Enemy(int screen_width, int screen_height, int grid_width, int grid_height)
            : screen_width(screen_width),
                screen_height(screen_height),
                grid_width(grid_width),
                grid_height(grid_height) { enemy.setStatus(false); 
                                        enemy.setSpeed(10);
                                        enemy.moveTo(screen_width-grid_width, (screen_height-grid_height/2)/2);
                                        enemy.addTexture(Graphics::instance().getEnemySprite());
                                        enemy.setStatus(true);

                                        }

        void Update();


        bool fire{false};
        bool win{false};
        int score{0};


        bool currentStatus(){ return enemy.currentStatus();}
        int currentY(){ return enemy.currentY();}
        int currentX(){ return enemy.currentX();}
        SDL_Texture* getTexture(){ return enemy.getTexture(); }
        int currentSpeed() {return enemy.currentSpeed();}


        void moveTo(int x, int y){ enemy.moveTo(x, y);}
        void addTexture(SDL_Texture *texture) { enemy.addTexture(texture); }
        void setStatus( bool isalive){ enemy.setStatus(isalive); }

    private:
        int screen_width;
        int screen_height;
        int grid_width;
        int grid_height;
        int degrees{0};
        int step_degrees{3};
        Entity enemy;

};

#endif