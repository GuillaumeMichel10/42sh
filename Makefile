##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

.PHONY: all val test clean fclean re

CFLAGS  += -W -Wall -Wextra -Wundef -g -lncurses -O2
LDFLAGS = -L./lib/my -lmy

SRC		=	$(wildcard src/*.c src/*/*.c)

OBJ		=	$(SRC:.c=.o)

NAME = mysh

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

test:
		make
		sleep 1
		./test/test.sh
		sleep 2
		./test/test2.sh

val:
		make
		valgrind ./$(NAME) > valgrind
		cat valgrind

clean:
		make clean -C ./lib/my
		rm -f $(OBJ)

fclean:                 clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all
