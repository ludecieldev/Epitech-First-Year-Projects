/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** live.c
*/

#include "corewar.h"

int live(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ,
    __attribute_maybe_unused__ process_t *process)
{
    for (u_int i = 0; i < corewar->champ_nb; i++)
        if (param->param[0] == (int)corewar->champions[i]->id) {
            corewar->champions[i]->last_live = corewar->cycle;
            corewar->live_nb++;
            write(1, "The player ", 11);
            my_putnbr(corewar->champions[i]->id);
            write(1, "(", 1);
            write(1, corewar->champions[i]->name,
                my_strlen(corewar->champions[i]->name));
            write(1, ")is alive.\n", 11);
        }
    if (corewar->live_nb == NBR_LIVE) {
        corewar->live_nb = 0;
        corewar->cycle_to_die -= CYCLE_DELTA;
    }
    return 0;
}
