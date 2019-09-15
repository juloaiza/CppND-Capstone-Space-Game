#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

// #include <unistd.h>
// #define GetCurrentDir getcwd

// std::string GetCurrentWorkingDir( void ) {
//   char buff[FILENAME_MAX];
//   GetCurrentDir( buff, FILENAME_MAX );
//   std::string current_working_dir(buff);
//   return current_working_dir;
// }

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{1280};
    constexpr std::size_t kScreenHeight{600};
    constexpr std::size_t kGridWidth{48};
    constexpr std::size_t kGridHeight{46};

    // std::cout << GetCurrentWorkingDir() << std::endl;

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    //std::cout << "Score: " << game.GetScore() << "\n";
    // std::cout << "Size: " << game.GetSize() << "\n";
    return 0;
}