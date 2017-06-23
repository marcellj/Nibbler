#include "StartGame.hpp"

StartGame::StartGame() {
  while(1) {
      if(collision()) {
          move(26, 34);
          printw("***GAME OVER DUDE***");
          break;
      }
      moveSnake();
      if(_direction == 'q')
          break;
      usleep(_delay);
  }
}

StartGame::~StartGame() {

}

StartGame::StartGame(StartGame const &src) {
  *this = src;
}

StartGame &StartGame::operator=(StartGame const &rhs) {
  if(this != &rhs)
    *this = rhs
  return *this;
}
