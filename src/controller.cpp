#include "controller.h"
#include <iostream>
#include "SDL.h"

#include "player.h"
#include "audio.h"



void Controller::HandleInput(bool &running, Player &player) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
        running = false;
        } else if (e.type == SDL_KEYUP) {
            player.direction = Player::Direction::kNone;
        }

    }

    const Uint8* keystates = SDL_GetKeyboardState( NULL );
    if( keystates[ SDL_SCANCODE_UP ] ) {
        player.direction = Player::Direction::kUp;
    }

    if( keystates[ SDL_SCANCODE_DOWN ] ) {
        player.direction = Player::Direction::kDown;
    }

    if( keystates[ SDL_SCANCODE_LEFT ] ) {
        player.direction = Player::Direction::kLeft;
    }

    if( keystates[ SDL_SCANCODE_RIGHT ] ) {
        player.direction = Player::Direction::kRight;
    }

    if( keystates[ SDL_SCANCODE_RETURN ] ) {
        player.hit_enter = true;
        Audio::instance().playClick();
    }

}