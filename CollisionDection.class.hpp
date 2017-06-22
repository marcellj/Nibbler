#ifndef CollisionDection_HPP
#define CollisionDection_HPP
#include "Snake.class.hpp"
#include "FoodEvent.class.hpp"

class CollisionDection {
private:


public:
  CollisionDection ( void );
  ~CollisionDection ( void );
  int moveBullets(BulletEvent *bullets, FoodEvent *foods);
  int movePlayer(Player hero);
  CollisionDection ( CollisionDection const & copy );
  CollisionDection & operator=( CollisionDection const & copy );
};

std::ostream & operator<<(std::ostream & o, CollisionDection const & rhs);
#endif
