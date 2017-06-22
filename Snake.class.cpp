#include "Snake.class.hpp"

void Snake::setX( int const value ) {x = value;}

int Snake::getX( void ) const {return x;}

void Snake::setY(int const value ) {y = value;}

int Snake::getY( void ) const {return y;}

void Snake::incX() {x++;}

void Snake::decX() {x--;}

void Snake::incY() {y++;}

void Snake::decY() {y--;}

Snake::Snake(Snake const & copy) {
  *this = copy;
}

Snake::~Snake ( void ) {
}

Snake::Snake( void ) {
  y = 30;
  x = 10;
}

Snake & Snake::operator=( Snake const & copy ) {
  if ( this != &copy ) {
    this->setX(copy.getX());
    this->setY(copy.getY());
  }
  return *this;
}

std::ostream & operator<<(std::ostream & o, Snake const & rhs)
{
    Snake copy(rhs);
    o << "This snake's and cords are x = " << copy.getX() << " y = " << copy.getY();
    return o;
}
