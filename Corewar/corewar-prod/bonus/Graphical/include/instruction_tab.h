/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** instruction_tab.h
*/

#ifndef INSTRUCTION_TAB_H
    #define INSTRUCTION_TAB_H
    #include "corewar.h"

static int (*instructions[17])(corewar_t *corewar, parameter_t *param,
    __attribute_maybe_unused__ champion_t *champ, process_t *process) =
    {0, &live, &ld_inst, &st_inst, &add, &sub, &and_inst, &or_inst, &xor_inst,
    &zjmp, &ldi, &sti, &my_fork, &lld, &lldi, &lfork, &aff};

#endif
