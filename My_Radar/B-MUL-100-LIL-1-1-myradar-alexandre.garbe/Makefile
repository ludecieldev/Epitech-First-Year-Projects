##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main/main.c	\
		src/main/init.c	\
		lib/my/my_putstr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_str_to_word_array.c	\
		lib/my/mini_printf.c	\
		lib/my/is_a_num.c	\
		src/main/parser.c	\
		src/main/file_error_handling.c	\
		src/radar/window_display.c	\
		src/radar/destroy.c	\
		lib/my/my_arg_to_int.c	\
		lib/my/count_words.c	\
		lib/my/my_strtok.c	\
		src/radar/create_tower.c	\
		src/radar/array_travel.c	\
		src/radar/create_plane.c	\
		src/main/help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	+=	-W -Wall -Wextra -g3

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window \
	-lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f *.o

re: fclean all

.PHONY:
	all clean fclean re
