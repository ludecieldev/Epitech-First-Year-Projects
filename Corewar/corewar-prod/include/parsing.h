/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** parsing.h
*/

#ifndef PARSING_H
    #define PARSING_H
    #include "corewar.h"

/*
 * parsing.c
*/
parsing_t *parsing(int ac, char **av);
void free_parsing(parsing_t *parse);

/*
 * setup_corewar.c
*/
corewar_t *setup_corewar(parsing_t *parse);
process_t *init_process(int id, void *mem_index, corewar_t *corewar);

#endif
