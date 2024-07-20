/*
** EPITECH PROJECT, 2024
** B_PSU_200_LIL_2_1_minishell1_enzo_dubeaurepaire
** File description:
** my_strndup.c
*/

#include "lib.h"

size_t len_to(char const *str, char c)
{
    size_t count = 0;

    for (; str[count] && str[count] != c; count++);
    return count;
}

char *my_strdup_to(char const *str, char c)
{
    char *ret = malloc(len_to(str, c) + 1);

    ret[len_to(str, c)] = 0;
    for (int i = 0; str[i] && str[i] != c; i++)
        ret[i] = str[i];
    return ret;
}

char *my_strndup(char const *str, size_t nb)
{
    char *ret;
    size_t len = my_strlen(str);

    if (nb < len)
        len = nb;
    ret = malloc(len + 1);
    ret[len] = 0;
    for (size_t i = 0; i < len; i++)
        ret[i] = str[i];
    return ret;
}
