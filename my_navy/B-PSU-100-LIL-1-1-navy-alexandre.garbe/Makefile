##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main/main.c	\
		src/map_management/create_blank_map.c	\
		src/pos_handler/error_pos_handler.c	\
		src/map_management/map_manager.c	\
		src/boat_management/add_boat.c	\
		src/pos_handler/get_pos.c	\
		src/map_printer/print_map.c	\
		src/game_management/game.c	\
		lib/my/str_to_wordarray.c	\
		lib/my/mini_printf.c	\
		lib/my/is_a_number.c	\
		src/connexion/signal.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_revstr.c  \
		lib/my/my_strcmp.c	\
		lib/my/my_atoi.c	\
		src/help/help.c	\
		lib/my/my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_navy

CFLAGS	+=	-W -Wall -Wextra -g3

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)
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
