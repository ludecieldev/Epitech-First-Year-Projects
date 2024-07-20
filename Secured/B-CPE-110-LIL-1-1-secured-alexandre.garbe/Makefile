##
## EPITECH PROJECT, 2023
## alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/hash/hash.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/mini_printf.c	\
		lib/my/my_strdup.c	\
		lib/my/int_count.c	\
		lib/my/get_ascii_value.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_revstr.c	\
		src/hash/hash.c	\
		src/hash/delete_hashtable.c	\
		src/hash/display_table.c	\
		src/hash/ht_delete.c	\
		src/hash/ht_insert.c	\
		src/hash/ht_search.c	\
		src/hash/new_hastable.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libhashtable.a

CFLAGS	+=	-W -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OBJ)
	rm -f vgcore.*

re:	fclean all

.PHONY:	all clean fclean re
