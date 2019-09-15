#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include "SDL_mixer.h"

//Singleton
class Audio
{
    public:
        static Audio& instance()
        {
            static Audio *instance = new Audio();
            return *instance;
        }

        void init();
        void playMusic();
        void stopMusic();
        void playFire();
        void playGameOver();
        void playExplosion();
        void playClick();  
    

    private:
        Audio() {} //Private constructor

        //The music that will be played
        Mix_Music *gMusic;

        //Sound Effect
        Mix_Chunk *gFired;
        Mix_Chunk *gExplosion;
        Mix_Chunk *gGameOver;
        Mix_Chunk *gClick;


};


#endif
