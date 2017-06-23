#include "SnakeClass.hpp"

SnakeClass::SnakeClass() {
    initscr();              //initialize screen
    nodelay(stdscr, true);  //starts immediately
    keypad(stdscr, true);		//initialize keypad
    noecho();               //letters will not be written to screen if pressed
    curs_set(0);            //sets appearance of the cursor based on the value of visibility. 0 = Invisible
    getmaxyx(stdscr, _max_height, _max_width);

    _direction = 'l';
    _snake_head = 'O';
    _border = '#';
    _food_char = '*';
    _food.x = 0;
    _food.y = 0;
    _snake_eat = false;

    //determines the snakes position on the screen
    for(int i = 0; i < 4; i++)
        _snake.push_back(SnakePosition(40 + i, 10));
		_points = 0;
    _delay = 110000;
		srand(time(0));
		foodPosition();

		//adds the border to the screen
    for(int i = 0; i < _max_width - 1; i++) {
        move(_max_height - 2, i);
        addch(_border);
    }
    for(int i = 0; i < _max_width - 1; i++) {
        move(0, i);
        addch(_border);
    }
    for(int i = 0; i < _max_height - 1; i++) {
        move(i, _max_width - 2);
        addch(_border);
    }
    for(int i = 0; i < _max_height - 1; i++) {
        move(i, 0);
        addch(_border);
    }

    //draws snake to the screen
    for(std::string::size_type i = 0; i < _snake.size(); i++) {
        move(_snake[i].y, _snake[i].x);
        addch(_snake_head);
    }

    //draws the food to the screen
    move(_food.y, _food.x);
    addch(_food_char);

    //writes the points to the screen
    move(_max_height - 1, 0);
    printw("%d", _points);
    refresh();
}

SnakeClass::~SnakeClass() {
    nodelay(stdscr, false);
    getch();
    endwin();
}

SnakeClass::SnakeClass(SnakeClass const &src) {
	*this = src;
}

SnakeClass &SnakeClass::operator=(SnakeClass const &rhs) {
	if(this != &rhs)
		*this = rhs;
	return *this;
}

void SnakeClass::foodPosition() {
    while(1) {
        int temp_x, temp_y;

        temp_x = rand() % _max_width + 1;
        temp_y = rand() % _max_height + 1;
        for (std::string::size_type i = 0; i < _snake.size(); i++)
            if (_snake[i].x == temp_x && _snake[i].y == temp_y)
                continue;
        if (temp_x >= _max_width - 2 || temp_y >= _max_height - 3)
            continue;
        _food.x = temp_x;
        _food.y = temp_y;
        break;
    }
    move(_food.y, _food.x);
    addch(_food_char);
    refresh();
}

bool SnakeClass::collision() {
    //if it collides with the borders
    if(_snake[0].x == 0 || _snake[0].x == _max_width - 1
            || _snake[0].y == 0 || _snake[0].y == _max_height - 2)
        return true;
    //if it collides with itself
    for(std::string::size_type i = 2; i < _snake.size(); i++)
        if(_snake[0].x == _snake[i].x && _snake[i].y == _snake[0].y)
            return true;
    //if it eats food, add points and change foods position
    if(_snake[0].x == _food.x && _snake[0].y == _food.y) {
        _snake_eat = true;
        foodPosition();
        _points += 10;
        move(_max_height - 1, 0);
        printw("%d", _points);
        if((_points % 50) == 0)
            _delay -= 20000;
    }
    else
        _snake_eat = false;
    return false;
}

void SnakeClass::moveSnake() {
    int     temp;

    temp = getch();
    switch(temp) {
			case KEY_LEFT:
				if(_direction != 'r')
					_direction = 'l';
        break;
      case KEY_UP:
        if(_direction != 'd')
					_direction = 'u';
        break;
      case KEY_DOWN:
        if(_direction != 'u')
          _direction = 'd';
				break;
      case KEY_RIGHT:
        if(_direction != 'l')
          _direction = 'r';
				break;
      case KEY_BACKSPACE:
        _direction = 'q';
        break;
    }
    //if it doesn't get food, the last part of the snake it deleted and
    //a new snake part gets popped onto the front.
    if(!_snake_eat) {
        move(_snake[_snake.size() - 1].y, _snake[_snake.size() - 1].x);
        addch(' ');
        refresh();
        _snake.pop_back();
    }

    if(_direction == 'l')
        _snake.insert(_snake.begin(), SnakePosition(_snake[0].x - 1, _snake[0].y));
    else if(_direction == 'r')
        _snake.insert(_snake.begin(), SnakePosition(_snake[0].x + 1, _snake[0].y));
    else if(_direction == 'u')
        _snake.insert(_snake.begin(), SnakePosition(_snake[0].x, _snake[0].y - 1));
    else if(_direction == 'd')
        _snake.insert(_snake.begin(), SnakePosition(_snake[0].x, _snake[0].y + 1));
    move(_snake[0].y, _snake[0].x);
    addch(_snake_head);
    refresh();
}

void SnakeClass::startGame() {
    while(1) {
        if(collision()) {
            move(26, 34);
            printw("***GAME OVER DUDE***");
            break;
        }
        moveSnake();
        if(_direction == 'q')
            break;
        usleep(_delay);
    }
}
