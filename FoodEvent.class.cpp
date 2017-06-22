#include "FoodEvent.class.hpp"

int FoodEvent::getFoodCount() { return enemy_count; }

Food *FoodEvent::getEnemies() { return foods; }

void FoodEvent::setFoodCount(int new_count) { enemy_count = new_count; }

FoodEvent::FoodEvent( void ) {
	enemy_count = 0;
	s = 0;
}

FoodEvent::FoodEvent(FoodEvent const & copy) {
*this = copy;
}
FoodEvent::FoodEvent( int const foods ) {
	enemy_count = foods;
}

FoodEvent::~FoodEvent ( void ) {
}

FoodEvent & FoodEvent::operator=( FoodEvent const & copy ) {
	if ( this != &copy ) {
		*this = copy;
	}
	return *this;
}

void FoodEvent::moveEnemies() {
	for (int i = 0; i < enemy_count; i++) {
		foods[i].Move();
	}
}

void FoodEvent::genFood( void ) {
	int max_x = 275;
	int max_y = 62;
	int x;
	int y;

	srand((unsigned)time(0));
	s += rand();
	srand((unsigned)time(0) + s++);
	y = ((rand() % max_y));
	x = max_x;
	foods[enemy_count].setX(max_x);
	foods[enemy_count].setY(y);
	enemy_count++;
}

void FoodEvent::desFood(int pos) {
	enemy_count--;
	for (int i = pos; i < enemy_count; i++) {
		foods[i].setX(foods[i + 1].getX());
		foods[i].setY(foods[i + 1].getY());
	}
}

std::ostream & operator<<(std::ostream & o, FoodEvent const & rhs)
{
	FoodEvent copy(rhs);
	o  << "Amount of foods alive." << copy.getFoodCount();
	return o;
}