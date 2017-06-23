#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include <ncurses.h>
#include "SnakePosition.hpp"

#ifndef SNAKECLASS_HPP
#define SNAKECLASS_HPP

class SnakeClass {
public:
	SnakeClass();
	~SnakeClass();
	SnakeClass(SnakeClass const &src);
  SnakeClass &operator=(SnakeClass const &rhs);

private:
  int   _points;
	int		_delay;
	int		_max_width;
	int		_max_height;
  char	_direction;
	char	_snake_head;
	char	_border;
	char	_food_char;
  bool	_snake_eat;

  SnakePosition   _food;
  std::vector<SnakePosition> _snake;

  void    foodPosition();
  void    moveSnake();
  bool    collision();
};

#endif
