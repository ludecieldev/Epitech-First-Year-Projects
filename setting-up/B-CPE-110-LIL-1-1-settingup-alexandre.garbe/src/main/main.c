/*
** EPITECH PROJECT, 2023
** settingup
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../lib/my/settingup.h"

int init_values(char **av, values_t *values)
{
    values->rows = 0;
    values->cols = 0;
    values->max_size = 0;
    values->max_i = -1;
    values->max_j = -1;
    values->map = map_load(av[1]);
    if (values->map == NULL)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    values_t values;

    if (ac != 2)
        return 84;
    init_values(av, &values);
    if (values.map == NULL)
        return 84;
    while (values.map[values.rows] != NULL)
        values.rows++;
    values.cols = my_strlen(values.map[1]);
    find_and_mark_largest_square(&values);
    for (int i = 0; i < values.rows; i++){
        if (i == (values.rows - 1)){
            mini_printf("%s", values.map[i]);
        } else
            mini_printf("%s\n", values.map[i]);
    }
    return 0;
}
