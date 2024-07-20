##
## EPITECH PROJECT, 2023
## alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main/main.c	\
		src/functions/add.c	\
		src/functions/del.c	\
		src/functions/disp.c	\
		src/functions/sort.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strcmp.c	\
		lib/my/mini_printf.c	\
		lib/my/my_strdup.c	\
		lib/my/my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

CFLAGS	+=	-W -Wall -Wextra -g3 -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L./ -lshell

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f vgcore.*

re:	fclean all

.PHONY:	all clean fclean re
