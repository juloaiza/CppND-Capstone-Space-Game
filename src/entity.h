#ifndef ENTITY_H
#define ENTITY_H

#include "SDL.h"

class Entity {
    private:
        int e_x;
        int e_y;
        int e_speed;
        bool e_isalive;
        SDL_Texture *e_texture;

    public:
        
        // A default constructor
        Entity() : e_x(1), e_y(1), e_speed(0), e_isalive(true), e_texture(nullptr){}

        // A specific constructor
        Entity(int x, int y, int speed, bool isalive, SDL_Texture *texture) : e_x(x), e_y(y), e_speed(speed), e_isalive(isalive), e_texture(texture){}
       
        void moveTo(int x, int y);

        void setSpeed(int speed);

        void setStatus( bool isalive);

        void addTexture(SDL_Texture *texture);

        int currentY();

        int currentX();

        int currentSpeed();

        bool currentStatus();

        SDL_Texture* getTexture();

};
#endif
