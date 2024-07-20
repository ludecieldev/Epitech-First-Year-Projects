##
## EPITECH PROJECT, 2023
## 101pong
## File description:
## Makefile
##

SRC	=	src/calc/speed_vector.c	\
		src/main/101pong.c 	\
		src/main/main.c	\
		src/calc/paddle_checker.c	\
		src/main/errorcase.c 	

NAME	=	101pong 	

all	:
	echo "Starting.."
	-gcc -g $(SRC) -o $(NAME) -lm
	-cp lib/my/my.h include/
	echo "Compile done."

clean :
	-rm include/my.h

fclean :
	-make clean -s
	-rm $(NAME)

re : 
	-make fclean -s
	-make all
