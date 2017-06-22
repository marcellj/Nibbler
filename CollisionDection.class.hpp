#ifndef COLLISIONDECTION_HPP
#define COLLISIONDECTION_HPP
#include "Snake.class.hpp"
#include "FoodEvent.class.hpp"
#include "Game.class.hpp"

class CollisionDection {
private:


public:
  CollisionDection ( void );
  ~CollisionDection ( void );
	CollisionDection ( CollisionDection const & copy );
	CollisionDection & operator=( CollisionDection const & copy );

  // int moveBullets(BulletEvent *bullets, FoodEvent *foods);
  int movePlayer(Player hero);
};

std::ostream & operator<<(std::ostream & o, CollisionDection const & rhs);

#endif
