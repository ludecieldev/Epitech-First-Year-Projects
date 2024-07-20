##
## EPITECH PROJECT, 2023
## B-CPE-110-LIL-1-1-settingup-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main/map_loader.c	\
		src/main/main.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/mini_printf.c	\
		lib/my/str_to_wordarray.c	\
		src/main/map_replace.c

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

CFLAGS	=	-Wall -Wextra -I./include

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f vgcore*

re:	fclean all

.PHONY:	all clean fclean re
