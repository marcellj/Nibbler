#include "Draw.class.hpp"

Draw::Draw(Draw const & copy) {
  *this = copy;
}

Draw::Draw( void ) {
}

Draw::~Draw ( void ) {
}

void Draw::Redraw(Player hero, FoodEvent *foods) {
  mvprintw(hero.getY(), hero.getX(), ">");
  // Bullet *allbullets = bullets->getBullets();
	Food *allEmemies = foods->getEnemies();
  for (int i = 0; i < bullets->getBulletCount(); i++) {
      mvprintw(allbullets[i].getY(), allbullets[i].getX(), "-");
      allbullets[i].setX(allbullets[i].getX() + 1);
  }
	if (foods->getFoodCount()) {}
	for (int i = 0; i < foods->getFoodCount(); i++) {
		mvprintw(allEmemies[i].getY(), allEmemies[i].getX(), "<");
		mvprintw(allEmemies[i].getY(), allEmemies[i].getX() - 1 , "-");
		//allEmemies[i].setX(allEmemies[i].getX() - 1);
	}
}

Draw & Draw::operator=( Draw const & copy ) {
  Draw new_draw(copy);
  return *this;
}
