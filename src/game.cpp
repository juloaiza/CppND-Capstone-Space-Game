#include "game.h"
#include <iostream>
#include "SDL.h"
#include <chrono>
#include <thread>
#include <random>
#include "audio.h"

//MAIN.C

Game::Game(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height)
    : player(screen_width, screen_height, grid_width, grid_height),
      enemy(screen_width, screen_height, grid_width, grid_height),
      bullet(screen_width, screen_height){  Audio::instance().init();
                                            Audio::instance().playMusic();
                                          }

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) {

  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    /* Sleep at every iteration to reduce CPU usage */
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

      // Input, Update, Render - the main game loop.
      controller.HandleInput(running, player);

      if (player.hit_enter) {
        if (!stop_game) {
          Update();
        
        //renderer.Render(snake, food);
        renderer.Render(player, bullet, enemy);
        }
       }

      if (enemy.win){
        stop_game = true;
      }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      //renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


 void Game::Update() {

    player.Update();
    bullet.Update();
    enemy.Update();

}

//int Game::GetScore() const { return score; }
