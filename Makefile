NAME	=	nibbler

SRCS	=	*.cpp

LIB		=	-lncurses

all:	$(NAME)

$(NAME):	clean
	clang++ -Wall -Werror -Wextra $(LIB) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)
