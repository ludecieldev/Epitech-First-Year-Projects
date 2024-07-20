##
## EPITECH PROJECT, 2023
## alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main/main.c	\
		src/main/map_loader.c	\
		src/main/find_map_info.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_put_nbr.c	\
		lib/my/mini_printf.c	\
		lib/my/my_str_to_word_array.c	\
		src/main/game.c	\
		src/movements/move_player.c	\
		src/movements/move_down.c	\
		src/movements/move_up.c	\
		src/movements/move_left.c	\
		src/movements/move_right.c	\
		src/main/find_player.c	\
		src/movements/replace_storage.c	\
		src/main/case_space.c	\
		src/main/victory_loss_management.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra -g3 -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
