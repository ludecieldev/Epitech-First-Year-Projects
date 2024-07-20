/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** parsing.c
*/

#include "corewar.h"

void free_parsing(parsing_t *parse)
{
    for (int i = 0; i < 4 && parse->champion_path[i]; i++)
        free(parse->champion_path[i]);
    free(parse);
}

static parsing_t *init_parsing(void)
{
    parsing_t *parse = malloc(sizeof(parsing_t));

    parse->champion_path[0] = NULL;
    parse->champion_path[1] = NULL;
    parse->champion_path[2] = NULL;
    parse->champion_path[3] = NULL;
    parse->dump_flag = -1;
    parse->error = 84;
    return parse;
}

parsing_t *parsing(int ac, char **av)
{
    parsing_t *parse = init_parsing();
    int min_arg = 3;

    if (ac < min_arg)
        return parse;
    if (my_strcmp(av[1], "-dump\0") == 0) {
        min_arg += 2;
        if (!my_str_isnum(av[2]))
            return parse;
        parse->dump_flag = my_atoi(av[2]);
    }
    if (ac < min_arg || ac > min_arg + 2)
        return parse;
    for (int i = min_arg - 2; i < ac; i++)
        parse->champion_path[i - (min_arg - 2)] = my_strdup(av[i]);
    parse->error = 0;
    return parse;
}
