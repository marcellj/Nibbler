#ifndef DRAW_HPP
#define DRAW_HPP
#include <ncurses.h>
#include <iostream>
#include <string>
#include "Snake.class.hpp"
#include "FoodEvent.class.hpp"
#include "Game.class.hpp"

class Draw {
public:
  Draw ( void );
  Draw ( int const n );
  Draw ( Draw const & copy );
  Draw & operator=( Draw const & copy );
  ~Draw ( void );

	void Redraw(Player hero, FoodEvent *foods);
};

std::ostream & operator<<(std::ostream & o, Draw const & rhs);

#endif
