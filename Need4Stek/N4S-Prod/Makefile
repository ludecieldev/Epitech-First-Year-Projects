##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main/main.c \
		func/str_to_wordarray.c	\
		src/command/car_backward.c	\
		src/command/car_forward.c	\
		src/command/get_info_lidar.c	\
		src/command/get_next_line.c	\
		src/command/start_simulation.c	\
		src/command/stop_simulation.c	\
		src/command/wheel_dir.c	\
		src/lidar_interpreter/lidar_interpreter.c	\
		src/lidar_interpreter/find_lowest.c

OBJ     =   $(SRC:.c=.o)
DEPS    =   $(OBJ:.o=.d)

NAME    =   ai

CFLAGS  +=  -W -Wall -Wextra -g3 -MMD -MP -I./include
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

tests_run: all
	@./$(NAME)

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
