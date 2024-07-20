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
    parse->champions_id[0] = -1;
    parse->champions_id[1] = -1;
    parse->champions_id[2] = -1;
    parse->champions_id[3] = -1;
    parse->champions_start[0] = -1;
    parse->champions_start[1] = -1;
    parse->champions_start[2] = -1;
    parse->champions_start[3] = -1;
    parse->dump_flag = -1;
    parse->error = 84;
    return parse;
}

int check_flags(parsing_t *parse, char **av, int lim[2], int i)
{
    if (lim[0] == -1 || lim[0] >= lim[1])
        return -1;
    if (my_strcmp(av[lim[0]], "-a\0") == 0) {
        if (lim[0] + 1 >= lim[1])
            return -1;
        if (!my_str_isnum(av[lim[0] + 1]))
            return -1;
        parse->champions_start[i] = my_atoi(av[lim[0] + 1]);
        lim[0] += 2;
        return lim[0];
    }
    if (my_strcmp(av[lim[0]], "-n\0") == 0) {
        if (lim[0] + 1 >= lim[1])
            return -1;
        if (!my_str_isnum(av[lim[0] + 1]))
            return -1;
        parse->champions_id[i] = my_atoi(av[lim[0] + 1]);
        lim[0] += 2;
    }
    return lim[0];
}

int parse_dump(parsing_t *parse, char **av, int index, int ac)
{
    if (index >= ac)
        return -1;
    if (my_strcmp(av[index], "-dump\0") == 0) {
        index++;
        if (index >= ac)
            return -1;
        if (!my_str_isnum(av[index]))
            return -1;
        parse->dump_flag = my_atoi(av[index]);
        index++;
    }
    return index;
}

static int get_id(int ids[4])
{
    int index = 0;
    int found = 0;

    for (int i = 0;; i++) {
        if (index != ids[i % 4])
            found++;
        if (index == ids[i % 4]) {
            found = 0;
            index++;
        }
        if (found == 4)
            return index;
    }
}

static void set_id(parsing_t *parse)
{
    for (int i = 0; i < 4; i++) {
        if (parse->champions_id[i] == -1) {
            parse->champions_id[i] = get_id(parse->champions_id);
        }
    }
}

parsing_t *parsing(int ac, char **av)
{
    parsing_t *parse = init_parsing();
    int index = 1;
    int i = 0;

    index = parse_dump(parse, av, index, ac);
    if (index == -1)
        return parse;
    for (; i < 4 && index < ac; i++) {
        index = check_flags(parse, av, (int[2]){index, ac}, i);
        index = check_flags(parse, av, (int[2]){index, ac}, i);
        if (index < 0 || index >= ac)
            return parse;
        parse->champion_path[i] = my_strdup(av[index]);
        index++;
    }
    if (i >= 2) {
        parse->error = 0;
        set_id(parse);
    }
    return parse;
}
