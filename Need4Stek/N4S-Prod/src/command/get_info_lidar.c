/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** get_info_lidar
*/

#include "n4s.h"

static double *string_to_double_array(char *str)
{
    int count = 0;
    char *token = strtok(str, ":");
    double *array = malloc(sizeof(double) * 32);

    while (token != NULL) {
        if (count >= 2 && count < 32) {
            array[count - 2] = atof(token);
        }
        token = strtok(NULL, ":");
        count++;
    }
    return array;
}

void get_info_lidar(n4s_t *n4s)
{
    char *str = NULL;

    dprintf(1, "GET_INFO_LIDAR\n");
    fprintf(stderr, "Getting lidar info\n");
    str = get_next_line(0);
    if (str == NULL)
        exit(84);
    n4s->str = str;
    n4s->lidar = string_to_double_array(str);
    for (int i = 0; i < 32; i++)
        fprintf(stderr, "Lidar[%d]: %.2f\n", i, n4s->lidar[i]);
}
