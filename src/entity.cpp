#include "entity.h"
#include <iostream>

void Entity::moveTo(int x, int y){
    e_x = x;
    e_y = y;
}

void Entity::setSpeed(int speed){
    e_speed = speed;
}

void Entity::setStatus( bool isalive){
    e_isalive = isalive;
}


void Entity::addTexture(SDL_Texture *texture){
    e_texture = texture;
}


int Entity::currentY() {
    return e_y;
}


int Entity::currentX(){
    return e_x;
}

int Entity::currentSpeed(){
    return e_speed;
}

bool Entity::currentStatus(){
    return e_isalive;
}

SDL_Texture* Entity::getTexture(){
    return e_texture;
}

