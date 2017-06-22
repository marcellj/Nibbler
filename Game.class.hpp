#ifndef GAME_HPP
#define GAME_HPP
#include "FoodEvent.class.hpp"
#include "Draw.class.hpp"
#include "Snake.class.hpp"
#include "CollisionDection.class.hpp"
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <ncurses.h>
#include <string>

class Game {
private:
  Player hero;
	FoodEvent foods;
  CollisionDection dection;
  int score;

public:
  Game ( void );
  Game ( Game const & copy );
  Game & operator=( Game const & copy );
  ~Game ( void );

  void inputHandle(int c);
  Snake getSnake();
  void setHero(Snake new_snake);
  void start();
};

std::ostream & operator<<(std::ostream & o, Game const & rhs);

#endif
