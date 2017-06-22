#ifndef Draw_HPP
#define Draw_HPP
#include <ncurses.h>
#include <iostream>
#include <string>
#include "Snake.class.hpp"
#include "BulletEvent.class.hpp"
#include "FoodEvent.class.hpp"

class Draw {
public:
  Draw ( void );
  Draw ( int const n );
  Draw ( Draw const & copy );
  void Redraw(Player hero, FoodEvent *foods);
  Draw & operator=( Draw const & copy );
  ~Draw ( void );
};

std::ostream & operator<<(std::ostream & o, Draw const & rhs);
#endif
