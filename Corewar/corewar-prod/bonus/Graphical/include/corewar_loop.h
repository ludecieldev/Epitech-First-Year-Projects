/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** corewar_loop.h
*/

#ifndef COREWAR_LOOP_H
    #define COREWAR_LOOP_H
    #include "corewar.h"
    #include "memory_meta.h"

/*
 * check_win.c
*/
_Bool is_win(corewar_t *corewar);

/*
 * corewar_loop.c
*/
void corewar_loop(corewar_t *corewar, memory_meta_t *meta)

/*
 * get_address.c
*/
char *get_address(char *mem, char const *address);

#endif
