#ifndef FoodEvent_HPP
#define FoodEvent_HPP
#include <ncurses.h>
#include <iostream>
#include <string>
#include "Food.class.hpp"

class FoodEvent {
private:
	Food foods[1024];
	int food_count;
	int s;

public:
	FoodEvent ( void );
	FoodEvent ( int const foods );
	FoodEvent ( FoodEvent const & copy );
	FoodEvent & operator=( FoodEvent const & copy );
	~FoodEvent ( void );
	void moveEnemies();
	void genFood(void);
	void desFood(int pos);
	Food *getEnemies();
	int getFoodCount();
	void setFoodCount(int new_count);
};

std::ostream & operator<<(std::ostream & o, FoodEvent const & rhs);
#endif