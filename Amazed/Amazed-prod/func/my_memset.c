/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.garbe
** File description:
** my_memset.c
** Author:
** ludeciel
*/

#include "amazed.h"

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;

    while (n) {
        *ptr = (unsigned char)c;
        ptr++;
        n--;
    }
    return s;
}
