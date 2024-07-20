/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** add_sub.c
*/

#include "corewar.h"

int add(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg1 = get_arg(param->param[0], REG_T, process, corewar);
    int arg2 = get_arg(param->param[1], REG_T, process, corewar);

    if (arg1 + arg2 == 0)
        process->carry = 1;
    else
        process->carry = 0;
    if (param->param[2] % REG_NUMBER - 1 < 0)
        return 0;
    process->reg[param->param[2] % REG_NUMBER - 1] = arg2 + arg1;
    return 0;
}

int sub(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg1 = get_arg(param->param[0], REG_T, process, corewar);
    int arg2 = get_arg(param->param[1], REG_T, process, corewar);

    if (arg1 - arg2 == 0)
        process->carry = 1;
    else
        process->carry = 0;
    if (param->param[2] % REG_NUMBER - 1 < 0)
        return 0;
    process->reg[param->param[2] % REG_NUMBER - 1] = arg1 - arg2;
    return 0;
}
