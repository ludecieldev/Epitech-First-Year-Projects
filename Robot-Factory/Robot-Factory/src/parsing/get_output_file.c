/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** get_output_file.c
*/

#include "../../include/my.h"

int get_distance_to_name(char const *path)
{
    int distance = 0;

    for (; path[distance]; distance++)
        if (path[distance] == '/')
            return distance + 1;
    return 0;
}

FILE *get_output_file(char *input_name)
{
    char *output_name;
    FILE *output;

    input_name += get_distance_to_name(input_name);
    if (my_strlen(input_name) < 2 || (input_name[my_strlen(input_name)] == 's'
        && input_name[my_strlen(input_name) - 1] == '.')) {
        output_name = malloc(my_strlen(input_name) + 5);
        my_strcpy(output_name, input_name);
        my_strcat(output_name, ".cor\0");
        output = fopen(output_name, "w+");
        free(output_name);
        return output;
    }
    output_name = malloc(my_strlen(input_name) + 3);
    output_name[0] = 0;
    my_strncpy(output_name, input_name, my_strlen(input_name) - 2);
    my_strcat(output_name, ".cor\0");
    output = fopen(output_name, "w+");
    free(output_name);
    return output;
}
