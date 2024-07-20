##
## EPITECH PROJECT, 2023
## B-PSU-100-LIL-1-1-myls-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/flags/flag_a.c	\
		src/flags/flag_l.c	\
		src/flags/flag_d.c	\
		src/flags/flag_t.c	\
		src/flags/flag_identifier.c	\
		src/flags/flag_r_maj.c	\
		src/flags/flag_r_min.c	\
		src/main/my_ls.c	\
		src/main/main.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/mini_printf.c	\
		lib/my/my_strlen.c	\
		src/main/errorcase.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	+=	-W -Wall -Wextra

all:
	gcc -o $(NAME) $(SRC) -g3
clean:
	rm -f src/flags/*.o
	rm -f src/main/*.o
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: 
	all clean fclean re
