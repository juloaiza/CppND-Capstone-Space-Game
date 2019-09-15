#include "player.h"
#include <cmath>
#include <iostream>


void Player::Update() {
  int x = currentX();
  int y = currentY();
   
  switch (direction) {
    case Player::Direction::kUp:
      if (y > 0) {
        y -= 10;
      }
      break;

    case Player::Direction::kDown:
      if (y < screen_height - grid_height) {
        y += 10;
      }
      break;

    case Player::Direction::kLeft:
      if (x > 0) {
        x -= 10;
      }
      break;

    case Player::Direction::kRight:
      if (x < screen_width - grid_width) {
        x += 10;
      }
      break;
    
  }
  
  moveTo(x,y);
    
}

