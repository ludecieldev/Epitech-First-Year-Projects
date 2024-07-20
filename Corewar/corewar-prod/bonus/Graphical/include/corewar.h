/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** corewar.h
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include "op.h"
    #include "../lib/lib.h"
    #include "macros.h"
    #include "struct.h"
    #include "parsing.h"
    #include "instructions.h"
    #include "arguments.h"
    #include "corewar_loop.h"
    #include "memory_meta.h"
    #include <ncurses.h>
    #include <curses.h>

void dump_mem(WINDOW *win, char *mem, memory_meta_t *meta);
void init_ncurses(void);
#endif
