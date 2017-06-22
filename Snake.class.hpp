#ifndef Snake_HPP
#define Snake_HPP
#include <iostream>

class Snake {
private:
int x;
int y;

public:
  Snake ( void );
  Snake ( Snake const & copy );
  Snake & operator=( Snake const & copy );
  ~Snake ( void );
  int getX( void ) const;
  void setX( int const value );
  int getY( void ) const;
  void setY( int const value );
  void incX();
  void decX();
  void incY();
  void decY();
};

std::ostream & operator<<(std::ostream & o, Snake const & rhs);
#endif
