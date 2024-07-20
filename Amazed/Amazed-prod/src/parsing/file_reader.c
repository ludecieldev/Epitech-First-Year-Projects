/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** file_reader
*/

#include "amazed.h"

int file_reader(void)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1) {
        my_putstr(line);
    }
    return 0;
}
