#include "CollisionDection.class.hpp"

CollisionDection::CollisionDection(CollisionDection const & copy) {
  *this = copy;
}

CollisionDection::CollisionDection( void ) {
}

CollisionDection::~CollisionDection ( void ) {
}

CollisionDection & CollisionDection::operator=( CollisionDection const & copy ) {
  if ( this != &copy ) {
    *this = copy;
  }
  return *this;
}

int CollisionDection::moveBullets(BulletEvent *bullets, FoodEvent *foods) {
	Food *allfoods = foods->getEnemies();
	for (int j = 0; j < foods->getFoodCount(); j++) {
		for (int i = 0; i < bullets->getBulletCount(); i++) {
			if (allfoods[j].getY() ==  && allfoods[j].getX() ==  {
				foods->desFood(j);
			}
			else if (allbullets[i].getX() ==  271) {
				bullets->desBullet(i);
			}
		}
	}
  return 0;
}

int CollisionDection::movePlayer(Player hero) {
  if (hero.getX() == 0 && hero.getY() == 0)
    return 1;
  return 0;
}

std::ostream & operator<<(std::ostream & o, CollisionDection const & rhs)
{
    CollisionDection copy(rhs);
    o  << "This class detects collisions";
    return o;
}
