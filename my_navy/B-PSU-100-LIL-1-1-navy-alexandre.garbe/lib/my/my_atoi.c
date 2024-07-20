/*
** EPITECH PROJECT, 2023
** project my_hunter
** File description:
** function to animate my mob (rrrrrr)
*/

#include "../../include/navy.h"

char *my_itoa(int nbr)
{
    char *str = malloc(sizeof(char) * 10 + 1);
    int tmp = 0;

    if (nbr == 0) {
        return "0";
    }
    while (nbr > 0) {
        str[tmp] = nbr % 10 + '0';
        nbr = nbr / 10;
        tmp++;
    }
    str[tmp] = '\0';
    my_revstr(str);
    return str;
}
