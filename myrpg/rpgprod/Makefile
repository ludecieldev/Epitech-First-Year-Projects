##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/main.c										\
		src/button/menu/play_func.c						\
		src/button/menu/quit_func.c						\
		src/button/menu/settings_func.c					\
		src/button/change_state.c						\
		src/cursor/set_cursor.c							\
		src/engine/view/create_view.c					\
		src/engine/window/create_window.c				\
		src/env/verif_env.c								\
		src/events/handle_events.c						\
		src/events/screen_events.c						\
		src/events/texts_events.c						\
		src/game/events/game_events.c					\
		src/game/events/moves_events.c					\
		src/game/move/up.c								\
		src/game/move/down.c							\
		src/game/move/left.c							\
		src/game/move/right.c							\
		src/game/draw_game.c							\
		src/game/set_cursor_game.c						\
		src/loop/choose_loop.c							\
		src/loop/game_loop.c							\
		src/loop/menu_loop.c							\
		src/loop/settings_loop.c						\
		src/player/attack_player.c						\
		src/player/destroy_player.c						\
	    src/player/init_player.c						\
		src/return_function/my_rpg.c					\
		src/rpg_struct/create/create_cursor.c			\
		src/rpg_struct/create/create_menu.c				\
		src/rpg_struct/create/create_rpg.c				\
		src/rpg_struct/create/create_settings.c			\
		src/rpg_struct/create/create_slider.c			\
		src/rpg_struct/create/create_sprite.c			\
		src/rpg_struct/create/create_texts.c			\
		src/rpg_struct/create/create_window_struct.c	\
		src/rpg_struct/create/sf_set_functions.c		\
		src/rpg_struct/destroy/destroy_cursor.c			\
		src/rpg_struct/destroy/destroy_menu.c			\
		src/rpg_struct/destroy/destroy_rpg.c			\
		src/rpg_struct/destroy/destroy_texts.c			\
		src/rpg_struct/destroy/free_rpg.c				\
		src/settings/buttons/funcs_back.c				\
		src/settings/buttons/funcs_fps.c				\
		src/settings/buttons/funcs_on_off.c				\
		src/settings/buttons/funcs_res.c				\
		src/settings/events/settings_events.c			\
		src/settings/events/texts_events.c				\
		src/settings/functions_for_settings.c			\
		src/settings/text_color.c						\
		src/splash_screen/splash_screen.c				\
		src/splash_screen/update_splash_screen.c		\
		src/splash_screen/create_splash_screen.c		\
		src/window_draw/window_draw.c					\
		src/inventory/create_inventory.c				\
		src/inventory/destroy_inventory.c				\
		src/items/create_item.c							\
		src/items/destroy_item.c						\
		src/items/display_items.c						\
		src/items/load_items.c							\
		src/items/save_items.c							\
		src/enemy/init_enemy.c                          \
		src/enemy/destroy_enemy.c						\
		src/display_help/init_help.c 					\
		src/display_help/destroy_help.c					\
		src/pnj/init_pnj.c                              \
		src/pnj/destroy_pnj.c

OBJ     =   $(SRC:.c=.o)
DEPS    =   $(OBJ:.o=.d)

NAME    =   my_rpg

CFLAGS  +=  -W -Wall -Wextra -MMD -MP -I./include/
LDFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

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
	@printf "${YELLOW}LUD'S MAKEFILE | \
${CYAN}Started compilation of ${RED}$(TOTAL_FILES) files${NC}\n"

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@printf "${YELLOW}LUD'S MAKEFILE | ${BOLD_GREEN}Compilation done!${NC}\n"

%.o: %.c
	@printf "${CYAN}Compiling $< $(FILES_COMPILED)/$(TOTAL_FILES)...${NC}\r"
	@$(eval FILES_COMPILED=$(shell echo $$(($(FILES_COMPILED)+1))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN}Compiled $< $(FILES_COMPILED)/$(TOTAL_FILES)${NC}\n"

end_compilation:
	@if [ $(FILES_COMPILED) -eq $(TOTAL_FILES) ]; then \
		printf "${YELLOW}LUD'S MAKEFILE | ${BOLD_GREEN}All \
files compiled successfully!${NC}\n"; \
	else \
		printf "${YELLOW}LUD'S MAKEFILE | No new changes to compile.${NC}\n"; \
	fi

clean:
	@rm -f $(OBJ) $(DEPS)
	@printf "${YELLOW}LUD'S MAKEFILE | ${RED}Cleaning object files...${NC}\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${YELLOW}LUD'S MAKEFILE | ${RED}Full cleanup complete.\
 Executable removed.${NC}\n"

debug:
	@gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS) -g3
	@printf "${YELLOW}LUD'S MAKEFILE | ${BOLD_GREEN}Compilation D done!${NC}\n"

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
