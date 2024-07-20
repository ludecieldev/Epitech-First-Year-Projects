/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** aff.c
*/

#include "corewar.h"

int aff(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg = get_arg(param->param[0], REG_T, process, corewar) % 256;

    write(1, &arg, 1);
    write(1, "\n", 1);
    return 0;
}
