#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>

class Food {
private:
	int	x;
	int	y;
	bool active;

public:
	Food ( void );
	Food ( int const x, int const y);
	Food ( Food const & copy );
	Food & operator=( Food const & copy );
	Food & operator++();
	~Food ( void );

	int getX( void ) const;
	void setX( int const value );
	int getY( void ) const;
	void setY( int const value );
	void setActive(void);
	void Move( void );
};

#endif
