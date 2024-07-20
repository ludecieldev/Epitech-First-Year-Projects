/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** arguments.h
*/

#ifndef ARGUMENTS_H
    #define ARGUMENTS_H
    #include "corewar.h"

/*
 * get_args.c
*/
int get_arg(int param, char type, process_t *process, corewar_t *corewar);
char get_param_type(int param_info, int param_nb, int instruction);
int get_arg_no_mod(int param, char type, process_t *process,
    corewar_t *corewar);

#endif
