##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main/render_window.c \
		lib/my/mini_printf.c \
		src/main/main.c \
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		lib/my/my_put_nbr.c \
		lib/my/my_strlen.c	\
		src/main/init.c	\
		src/main/event_manager.c	\
		src/main/animation.c	\
		src/main/mouse_scope.c	\
		src/main/score_management.c	\
		lib/my/my_int_to_arg.c	\
		lib/my/my_revstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	+=	-W -Wall -Wextra

all:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window \
	-lcsfml-system -lcsfml-audio -g3
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
