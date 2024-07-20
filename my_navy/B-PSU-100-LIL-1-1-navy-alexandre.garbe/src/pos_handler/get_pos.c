/*
** EPITECH PROJECT, 2024
** navy
** File description:
** get_pos.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int get_pos(char *filepath, boat_t **boats)
{
    char *line = NULL;
    size_t len = 0;
    FILE *stream = fopen(filepath, "r");
    int i = 0;

    if (stream == NULL)
        return (84);
    while (getline(&line, &len, stream) != -1){
        if (error_pos_handling(line) == 1)
            return (84);
        if (add_boat(boats, line, i) == 84)
            return (84);
        i++;
    }
    fclose(stream);
    return (0);
}
