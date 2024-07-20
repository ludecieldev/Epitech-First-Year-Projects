/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** zjmp.c
*/

#include "corewar.h"

int zjmp(__attribute_maybe_unused__ corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    if (process->carry == 0)
        return 0;
    process->pc = get_address(process->mem, process->param->pc +
        (char)param->param[0] % IDX_MOD);
    return 0;
}
