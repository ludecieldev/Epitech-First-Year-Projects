##
## EPITECH PROJECT, 2024
## B_PSU_200_LIL_2_1_minishell1_enzo_dubeaurepaire
## File description:
## Makefile
##

SRC	=	src/op.c \
		src/main.c \
		src/parsing/parsing.c \
		src/parsing/setup_corewar.c \
		src/arguments/get_args.c \
		src/instructions/add_sub.c \
		src/instructions/aff.c \
		src/instructions/and_or_xor.c \
		src/instructions/fork.c \
		src/instructions/ld.c \
		src/instructions/ldi.c \
		src/instructions/live.c \
		src/instructions/st.c \
		src/instructions/sti.c \
		src/instructions/zjmp.c \
		src/corewar_loop/check_win.c \
		src/corewar_loop/corewar_loop.c \
		src/corewar_loop/get_adress.c \
		lib/my_atoi.c \
		lib/my_bzero.c \
		lib/my_getnbr.c \
		lib/my_nb_to_str.c \
		lib/my_putnbr.c \
		lib/my_revstr.c \
		lib/my_str_islower.c \
		lib/my_str_isnum.c \
		lib/my_str_isupper.c \
		lib/my_str_to_word_array.c \
		lib/my_strcmp.c \
		lib/my_strcpy.c \
		lib/my_strdup.c \
		lib/my_strlen.c \
		lib/my_strcat.c \
		lib/my_strlowcase.c \
		lib/my_strncmp.c \
		lib/my_strncpy.c \
		lib/my_strndup.c \
		lib/my_strupcase.c	\
		src/ncurses/init_ncurses.c

OBJ     =   $(SRC:.c=.o)
DEPS    =   $(OBJ:.o=.d)

NAME    =   corewar

CFLAGS  +=  -W -Wall -Wextra -I./include
LDFLAGS = -lncurses
VALFLAG += -g3

CYAN    =   \033[0;36m
GREEN   =   \033[0;32m
BOLD_GREEN = \033[1;32m
RED     =   \033[1;91m
YELLOW  =   \033[1;33m
NC      =   \033[0m # No Color

TOTAL_FILES = $(words $(SRC))
FILES_COMPILED = 0

.SILENT:

all: start_compilation $(NAME) end_compilation

start_compilation:
	@printf "${YELLOW}Lud's Makefile | \
${CYAN}Started compilation of ${RED}$(TOTAL_FILES) files${NC}\n"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(VALFLAG) $(LDFLAGS)
	@printf "${YELLOW}Lud's Makefile | ${BOLD_GREEN}Compilation done!${NC}\n"

%.o: %.c
	@printf "${CYAN}Compiling $< $(FILES_COMPILED)/$(TOTAL_FILES)...${NC}\r"
	@$(eval FILES_COMPILED=$(shell echo $$(($(FILES_COMPILED)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN}Compiled $< $(FILES_COMPILED)/$(TOTAL_FILES)${NC}\n"

end_compilation:
	@if [ $(FILES_COMPILED) -eq $(TOTAL_FILES) ]; then \
		printf "${YELLOW}Lud's Makefile | ${BOLD_GREEN}All \
files compiled successfully!${NC}\n"; \
	else \
		printf "${YELLOW}Lud's Makefile | No new changes to compile.${NC}\n"; \
	fi

clean:
	@rm -f $(OBJ) $(DEPS)
	@printf "${YELLOW}Lud's Makefile | ${RED}Cleaning object files...${NC}\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${YELLOW}Lud's Makefile | ${RED}Full cleanup complete.\
 Executable removed.${NC}\n"

re: fclean all

valgrind: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

help:
	@echo "${BOLD_GREEN}Available targets:${NC}"
	@echo "${BOLD_GREEN}  all: Builds the project.${NC}"
	@echo "${BOLD_GREEN}  clean: Removes object \
files and dependency files.${NC}"
	@echo "${BOLD_GREEN}  fclean: Removes object files, dependency files, \
and the executable.${NC}"
	@echo "${BOLD_GREEN}  re: Rebuilds the project from scratch.${NC}"
	@echo "${BOLD_GREEN}  help: Displays this help.${NC}"
	@echo "${BOLD_GREEN}  clear: Clears the terminal.${NC}"


.PHONY: all clean fclean re start_compilation end_compilation help

-include $(DEPS)
