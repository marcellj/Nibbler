#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include <ncurses.h>

#ifndef STARTGAME_HPP
#define STARTGAME_HPP

class StartGame {
public:
  StartGame();
  ~StartGame();
  StartGame(StartGame const &src);
  StartGame &operator=(StartGame const &rhs);

  void startGame();
};

#endif
