/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** st.c
*/

#include "corewar.h"

int st_inst(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process)
{
    int arg = get_arg(param->param[0], REG_T, process, corewar);

    if (get_param_type(param->param_info, 2, 3) == REG_T) {
        if (param->param[1] % REG_NUMBER - 1 < 0)
            return 0;
        process->reg[param->param[1] % REG_NUMBER - 1] = arg;
        return 0;
    }
    for (int i = 0; i < 4; i++)
        *((char *)(get_address(process->mem, process->param->pc +
            param->param[1] % IDX_MOD + i))) =
            ((char *)&arg)[i];
    return 0;
}
