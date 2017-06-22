#include "Food.class.hpp"

Food::Food( void ) {
//	int max_x = 220;
//	int max_y = 62;
//
//	srand((unsigned)time(0));
//	y = max_y;
//	x = ((rand() % 10));
//	x = 1;
//	active = true;
}

Food::~Food( void ) {
}

Food::Food(int const xi, int const yi) {
	x = xi;
	y = yi;
	active = true;
}

Food & Food::operator=( Food const & copy ) {
	this->setX(copy.getX());
	this->setY(copy.getY());
	return *this;
}

void Food::setX( int const value ) {
	x = value;
}

int Food::getX( void ) const {
	return x;
}

void Food::setY(int const value ) {
	y = value;
}

int Food::getY( void ) const {
	return y;
}

void Food::Move( void ) {
	x--;
}

void Food::setActive( void ) {
	active = !active;
}
