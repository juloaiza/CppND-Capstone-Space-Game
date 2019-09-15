#include "audio.h"

void Audio::init(){

    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );

    //Load music
    gMusic = Mix_LoadMUS( "res/music/background.wav" );
    gFired = Mix_LoadWAV( "res/sound/laser.wav" );
    gExplosion = Mix_LoadWAV("res/sound/Explosion.wav");
    gGameOver = Mix_LoadWAV("res/sound/game-over.wav");
    gClick = Mix_LoadWAV("res/sound/click.wav");

}


void Audio::playMusic(){
    //Play the music
    Mix_PlayMusic( gMusic, -1 );
}

void Audio::stopMusic(){
    //Pause the music
    Mix_PauseMusic();
}

void Audio::playFire(){
    Mix_PlayChannel( -1, gFired, 0 );
}

void Audio::playGameOver(){
    Mix_PlayChannel( -1, gGameOver, 0 );
}


void Audio::playExplosion(){
    Mix_PlayChannel( -1, gExplosion, 0 );
}



void Audio::playClick(){
    Mix_PlayChannel( -1, gClick, 0 );
}