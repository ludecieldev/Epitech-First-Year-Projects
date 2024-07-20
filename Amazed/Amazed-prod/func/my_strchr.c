/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_strchr.c
** Author:
** ludeciel
*/

#include "amazed.h"

char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return &str[i];
    }
    return NULL;
}
