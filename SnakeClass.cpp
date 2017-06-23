#include "SnakeClass.hpp"

SnakeClass::SnakeClass() {
    initscr();              //initialize screen
    nodelay(stdscr, true);  //starts immediately
    keypad(stdscr, true);		//initialize keypad
    noecho();               //letters will not be written to screen if pressed
    curs_set(0);
    getmaxyx(stdscr, max_height, max_width);

    direction = 'l';
    snake_head = 'O';
    border = '#';
    food_char = '*';
    food.x = 0;
    food.y = 0;
    snake_eat = false;

    //determines the snakes position on the screen
    for(int i = 0; i < 4; i++)
        snake.push_back(SnakePosition(40 + i, 10));
		points = 0;
    delay = 110000;
		srand(time(0));
		foodPosition();

		//adds the border to the screen
    for(int i = 0; i < max_width - 1; i++) {
        move(max_height - 2, i);
        addch(border);
    }
    for(int i = 0; i < max_width - 1; i++) {
        move(0, i);
        addch(border);
    }
    for(int i = 0; i < max_height - 1; i++) {
        move(i, max_width - 2);
        addch(border);
    }
    for(int i = 0; i < max_height - 1; i++) {
        move(i, 0);
        addch(border);
    }

    //draws snake to the screen
    for(std::string::size_type i = 0; i < snake.size(); i++) {
        move(snake[i].y, snake[i].x);
        addch(snake_head);
    }

    //draws the food to the screen
    move(food.y, food.x);
    addch(food_char);

    //writes the points to the screen
    move(max_height - 1, 0);
    printw("%d", points);
    refresh();
}

SnakeClass::~SnakeClass() {
    nodelay(stdscr, false);
    getch();
    endwin();
}

//SnakeClass::SnakeClass(SnakeClass const &src) {
//    this->operator=(src);
//    return;
//}

//SnakeClass &SnakeClass::operator=(SnakeClass const &rhs) {
//    return *this;
//}

void SnakeClass::foodPosition() {
    while(1) {
        int temp_x, temp_y;

        temp_x = rand() % max_width + 1;
        temp_y = rand() % max_height + 1;
        for (std::string::size_type i = 0; i < snake.size(); i++)
            if (snake[i].x == temp_x && snake[i].y == temp_y)
                continue;
        if (temp_x >= max_width - 2 || temp_y >= max_height - 3)
            continue;
        food.x = temp_x;
        food.y = temp_y;
        break;
    }
    move(food.y, food.x);
    addch(food_char);
    refresh();
}

bool SnakeClass::collision() {
    //if it collides with the borders
    if(snake[0].x == 0 || snake[0].x == max_width - 1
            || snake[0].y == 0 || snake[0].y == max_height - 2)
        return true;
    //if it collides with itself
    for(std::string::size_type i = 2; i < snake.size(); i++)
        if(snake[0].x == snake[i].x && snake[i].y == snake[0].y)
            return true;
    //if it eats food, add points and change foods position
    if(snake[0].x == food.x && snake[0].y == food.y) {
        snake_eat = true;
        foodPosition();
        points += 10;
        move(max_height - 1, 0);
        printw("%d", points);
        if((points % 50) == 0)
            delay -= 20000;
    }
    else
        snake_eat = false;
    return false;
}

void SnakeClass::moveSnake() {
    int     temp;

    temp = getch();
    switch(temp) {
			case KEY_LEFT:
				if(direction != 'r')
					direction = 'l';
        break;
      case KEY_UP:
        if(direction != 'd')
					direction = 'u';
        break;
      case KEY_DOWN:
        if(direction != 'u')
          direction = 'd';
				break;
      case KEY_RIGHT:
        if(direction != 'l')
          direction = 'r';
				break;
      case KEY_BACKSPACE:
        direction = 'q';
        break;
    }
    //if it doesn't get food, the last part of the snake it deleted and
    //a new snake part gets popped onto the front.
    if(!snake_eat) {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        addch(' ');
        refresh();
        snake.pop_back();
    }

    if(direction == 'l')
        snake.insert(snake.begin(), SnakePosition(snake[0].x - 1, snake[0].y));
    else if(direction == 'r')
        snake.insert(snake.begin(), SnakePosition(snake[0].x + 1, snake[0].y));
    else if(direction == 'u')
        snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y - 1));
    else if(direction == 'd')
        snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y + 1));
    move(snake[0].y, snake[0].x);
    addch(snake_head);
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
        if(direction == 'q')
            break;
        usleep(delay);
    }
}
