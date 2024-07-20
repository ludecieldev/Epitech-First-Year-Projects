/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** instructions.h
*/

#ifndef INSTRUCTIONS_H
    #define INSTRUCTIONS_H
    #include "corewar.h"

/*
 * live.c
*/
int live(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * ld.c
*/
int ld_inst(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int lld(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * st.c
*/
int st_inst(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * add_sub.c
*/
int add(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int sub(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * and_or_xor.c
*/
int and_inst(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int or_inst(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int xor_inst(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * zjmp.c
*/
int zjmp(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * ldi.c
*/
int ldi(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int lldi(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * sti.c
*/
int sti(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * aff.c
*/
int aff(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

/*
 * fork.c
*/
int my_fork(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);
int lfork(corewar_t *corewar, parameter_t *param, champion_t *champ,
    process_t *process);

#endif
