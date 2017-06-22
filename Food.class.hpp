#ifndef CPP_BOOTCAMP_ENEMY_CLASS_HPP
#define CPP_BOOTCAMP_ENEMY_CLASS_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>
class Enemy {
private:
	int	x;
	int	y;
	bool active;
public:
	Enemy ( void );
	Enemy ( int const x, int const y);
	Enemy ( Enemy const & copy );
	Enemy & operator=( Enemy const & copy );
	Enemy & operator++();
	~Enemy ( void );
	int getX( void ) const;
	void setX( int const value );
	int getY( void ) const;
	void setY( int const value );
	void setActive(void);
	void Move( void );
};
#endif //CPP_BOOTCAMP_ENEMY_CLASS_HPP
