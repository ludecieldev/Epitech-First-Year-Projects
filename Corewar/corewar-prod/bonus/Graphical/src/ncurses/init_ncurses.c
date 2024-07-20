/*
** EPITECH PROJECT, 2024
** corewar-prod
** File description:
** init_ncurses
*/

#include "corewar.h"

void init_ncurses(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_MAGENTA, -1);
}

