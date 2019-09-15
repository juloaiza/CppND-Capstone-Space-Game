#include "bullet.h"
#include <cmath>
#include <iostream>
#include "audio.h"


void Bullet::Update() {
    int x = currentX();
    int y = currentY();

    const Uint8* keystates = SDL_GetKeyboardState( NULL );

    if( keystates[ SDL_SCANCODE_SPACE ] ) {
        fire = true;
        //std::cout<<"Fire -"<<currentY()<<"\n";
        if (!currentStatus()) {
            Audio::instance().playFire();
            setStatus(true);
        } 
    }


    if (currentStatus()){
        x+=currentSpeed();
        //y+=10;

        moveTo(x,y);

            if (x > 1280)
            {
                setStatus(false);;
            }
    }


    
}


