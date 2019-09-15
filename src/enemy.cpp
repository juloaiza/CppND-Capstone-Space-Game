#include "enemy.h"
#include <math.h> 
#include <iostream>
#include <random>
#include "audio.h"

#define PI 3.14159265

void Enemy::Update() {
     
    /* Init our random generation between 4 and 6 seconds */
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(3, 6);

    int x = currentX();
    int y = currentY();
    int period = 1;
    int amplitude = 200;

    if (!currentStatus()) {
        setStatus(true);
        x= -100; //dummy value
        enemy.addTexture(Graphics::instance().getEnemySprite());
        score -=1;
    }

    if (x < -1*grid_width) {
        enemy.moveTo(screen_width-grid_width, currentY() );
        step_degrees = distr(rd);
        score +=1;
    } else {
        
        if (degrees > 360){
            degrees = 0;
        }

        x -= enemy.currentSpeed();
        y = round(amplitude*sin (period*degrees*PI/180) + (screen_height-grid_height/2)/2);

        
        // std::cout<< degrees <<"\n";
        // std::cout<< y <<"\n";

        enemy.moveTo(x,y);

    }

    degrees += step_degrees; 

    if (score > 5){
        Audio::instance().stopMusic();
        Audio::instance().playGameOver();
        win = true;
        score = 0;

    }
    
}