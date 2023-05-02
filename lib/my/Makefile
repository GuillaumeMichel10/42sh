##
## EPITECH PROJECT, 2022
## libmy
## File description:
## Makefile
##

.PHONY: all clean fclean re

CFLAGS  += -W -Wall -Wextra -Wundef -pedantic -Werror

SRC     =       $(wildcard *.c)

OBJ     =		$(SRC:.c=.o)

NAME    =		libmy.a

all:	$(NAME)

$(NAME):        $(OBJ)
		ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:			fclean all
