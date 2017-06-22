#include "Game.class.hpp"

Snake Game::getSnake() { return hero; }

void Game::setHero(Snake new_player) { hero = new_player; }

Game::Game(Game const & copy) {
	*this = copy;
}

Game::Game( void ) {
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
//	FoodEvent allfoods;
//	foods = allfoods;
}

void Game::start() {
	Draw game;
	foods.setFoodCount(0);
	game.Redraw(hero, &foods);
	struct timeval	start;
	struct timeval	end;
	int ch;
	int game_over = 0;
	score = 0;
	while (game_over == 0 && score != 500) {
		gettimeofday(&start, NULL);
		clear();

		nodelay(stdscr, TRUE);
		ch = getch();
		if (ch != -1)
			inputHandle(ch);
		game_over = dection.moveSnake(hero);
		foods.moveEnemies();
		foods.genFood();
		game.Redraw(hero, &foods);
		refresh();
		score++;
		gettimeofday(&end, NULL);
		usleep( 60000 - (end.tv_usec - start.tv_usec) );
	}
}

void Game::inputHandle(int c) {
	switch(c) {
		case KEY_UP:
			if (hero.getY() != 0)
				hero.decY();
			break;
		case KEY_DOWN:
			if (hero.getY() != 62)
				hero.incY();
			break;
		case KEY_LEFT:
			if (hero.getX() != 0)
				hero.decX();
			break;
		case KEY_RIGHT:
			if (hero.getX() != 271)
				hero.incX();
			break;
	}
}

Game::~Game ( void ) {
	endwin();
	if (score == 5000)
		std::cout << "Yay you won!" << '\n';
	else
		std::cout << "Your score was " << score << '\n';
}

Game & Game::operator=( Game const & copy ) {
	if ( this != &copy ) {
		Game new_game(copy);
		setHero(new_game.getSnake());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Game const & rhs)
{
	Game copy(rhs);
	o  << "This game is running...";
	return o;
}
