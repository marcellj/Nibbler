NAME = snake

SRC = main.cpp CollisionDection.class.cpp Draw.class.cpp Food.class.cpp FoodEvent.class.cpp Game.class.cpp Snake.class.cpp

OFILES = main.o CollisionDection.class.o Draw.class.o Food.class.o FoodEvent.class.o Game.class.o Snake.class.o

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
