/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** check_win.c
*/

#include "corewar.h"

_Bool is_win(corewar_t *corewar)
{
    int alive_count = 0;

    for (u_int i = 0; i < corewar->champ_nb; i++) {
        if (corewar->champions[i]->alive)
            alive_count++;
    }
    if (alive_count <= 1)
        return 1;
    return 0;
}
