/*
** EPITECH PROJECT, 2024
** N4S-Prod
** File description:
** get_next_line
*/

#include "n4s.h"

char *get_next_line(int fd)
{
    char *str = NULL;
    char *buffer = malloc(sizeof(char) * 2);
    int i = 0;
    int size = 0;

    if (buffer == NULL)
        return (NULL);
    while (read(fd, buffer, 1) > 0 && buffer[0] != '\n') {
        str = realloc(str, sizeof(char) * (i + 1));
        str[i] = buffer[0];
        i++;
    }
    str = realloc(str, sizeof(char) * (i + 1));
    str[i] = '\0';
    free(buffer);
    return (str);
}
