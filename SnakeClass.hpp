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
private:
    int     points, delay, max_width, max_height;
    char    direction, snake_head, border, food_char;
    bool    snake_eat;

    SnakePosition   food;
    std::vector<SnakePosition> snake;

    void    foodPosition();
    void    moveSnake();
    bool    collision();

public:
    SnakeClass();
    ~SnakeClass();
//    SnakeClass(SnakeClass const &src);
//    SnakeClass &operator=(SnakeClass const &rhs);

    void    startGame();
};

#endif
