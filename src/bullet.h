#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "SDL.h"
#include "entity.h"
#include "graphics.h"

class Bullet {
    public:
        Bullet(int screen_width, int screen_height)
            : screen_width(screen_width),
                screen_height(screen_height) { bullet.setStatus(false); 
                                            bullet.setSpeed(20); 
                                            bullet.addTexture(Graphics::instance().getBulletSprite());
                                            }

        void Update();


        bool fire{false};

        bool currentStatus(){ return bullet.currentStatus();}
        int currentY(){ return bullet.currentY();}
        int currentX(){ return bullet.currentX();}
        SDL_Texture* getTexture(){ return bullet.getTexture(); }
        int currentSpeed() {return bullet.currentSpeed();}


        void moveTo(int x, int y){ bullet.moveTo(x, y);}
        void addTexture(SDL_Texture *texture) { bullet.addTexture(texture); }
        void setStatus( bool isalive){ bullet.setStatus(isalive); }

        //   void setSpeed(int speed){ setSpeed(speed); }


    private:
        int screen_width;
        int screen_height;
        Entity bullet;
};

#endif