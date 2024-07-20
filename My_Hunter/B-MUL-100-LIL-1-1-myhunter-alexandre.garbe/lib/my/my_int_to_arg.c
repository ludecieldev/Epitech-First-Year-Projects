/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** my_int_to_arg.c
** Author:
** ludeciel
*/

#include "my_hunter.h"

char *my_itoa(int nb)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 10);

    if (nb == 0)
        return ("0");
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = nb * -1;
    }
    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
