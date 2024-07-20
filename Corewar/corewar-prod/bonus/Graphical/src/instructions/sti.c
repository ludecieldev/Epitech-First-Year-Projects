/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** sti.c
*/

#include "corewar.h"

int sti(__attribute_maybe_unused__ corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int result = param->param[1] + param->param[2];

    if (result == 0)
        process->carry = 1;
    else
        process->carry = 0;
    for (int i = 0; i < REG_SIZE; i++) {
        *(get_address(process->mem, process->param->pc + result % IDX_MOD
            + i)) = *((char *)&process->reg[(param->param[0] - 1 + REG_SIZE -
            i - 1) % REG_NUMBER]);
    }
    return 0;
}
