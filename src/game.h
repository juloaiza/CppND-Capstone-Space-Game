#ifndef GAME_H
#define GAME_H

#include <random>

#include "controller.h"
#include "renderer.h"

#include "player.h"
#include "bullet.h"
#include "enemy.h"

class Game {
    public:
        Game(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height);
        void Run(Controller const &controller, Renderer &renderer,
                std::size_t target_frame_duration);
        // int GetScore() const;
        // int GetSize() const;

    private:

        Player player;
        Bullet bullet;
        Enemy enemy;


        int score{0};
        bool hit_enter{false};
        bool stop_game{false};
        void Update();
};

#endif