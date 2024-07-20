/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** ldi.c
*/

#include "corewar.h"

int ldi(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg1 = get_arg(param->param[0], get_param_type(param->param_info,
        1, 10), process, corewar);
    int arg2 = get_arg(param->param[1], get_param_type(param->param_info,
        2, 10), process, corewar);
    int result = arg1 + arg2;

    if (result == 0)
        process->carry = 1;
    else
        process->carry = 0;
    if (param->param[2] % REG_NUMBER - 1 < 0)
        return 0;
    process->reg[param->param[2] % REG_NUMBER - 1] = result;
    return 0;
}

int lldi(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg1 = get_arg_no_mod(param->param[0],
        get_param_type(param->param_info, 1, 10), process, corewar);
    int arg2 = get_arg_no_mod(param->param[1],
        get_param_type(param->param_info, 2, 10), process, corewar);
    int result = arg1 + arg2;

    if (result == 0)
        process->carry = 1;
    else
        process->carry = 0;
    if (param->param[2] % REG_NUMBER - 1 < 0)
        return 0;
    process->reg[param->param[2] % REG_NUMBER - 1] = result;
    return 0;
}
