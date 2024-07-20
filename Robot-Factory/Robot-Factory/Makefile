##
## EPITECH PROJECT, 2024
## B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
## File description:
## Makefile
##

SRC	=	src/main/main.c \
		src/main/op.c \
		src/parsing/parse_file.c \
		src/parsing/parse_header.c \
		src/utility/lens.c \
		src/write_in_file/write_header.c \
		src/parsing/get_output_file.c \
		src/utility/big_endian_writer.c \
		src/parsing/get_arg_type.c \
		src/parsing/parse_body.c	\
		lib/my_bzero.c \
        lib/my_getnbr.c \
        lib/my_nb_to_str.c \
        lib/my_putnbr.c \
        lib/my_str_islower.c \
        lib/my_str_isnum.c \
        lib/my_str_isupper.c \
        lib/my_str_to_word_array.c \
        lib/my_strcat.c \
        lib/my_strcpy.c \
        lib/my_strdup.c \
        lib/my_strlen.c \
        lib/my_revstr.c \
        lib/my_strlowcase.c \
        lib/my_strncmp.c \
        lib/my_strncpy.c \
        lib/my_strcmp.c \
        lib/my_atoi.c \
        lib/my_strupcase.c \
        lib/my_getnbr_plus.c \
        lib/my_better_str_to_word_array.c \
        src/linked_list/list1.c \
        src/linked_list/list2.c \
        src/linked_list/list3.c \
        src/parsing/get_labels.c \
        src/error_handling/error_handling.c

OBJ     =   $(SRC:.c=.o)
DEPS    =   $(OBJ:.o=.d)

NAME    =   asm

CFLAGS  +=  -W -Wall -Wextra -g3 -MMD -MP
LDFLAGS +=

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
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
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
