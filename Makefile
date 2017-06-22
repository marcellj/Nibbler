NAME = ft_retro

SRC = main.cpp Game.class.cpp Player.class.cpp Draw.class.cpp Bullet.class.cpp BulletEvent.class.cpp CollisionDection.class.cpp Enemy.class.cpp EnemyEvent.class.cpp

OFILES = main.o Game.class.o Player.class.o Draw.class.o Bullet.class.o BulletEvent.class.o CollisionDection.class.o

FLAGS = -Wall -Wextra -Werror

all:
	@clang++ $(FLAGS) $(SRC) -lncurses -o $(NAME)

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: re
	./$(NAME)
