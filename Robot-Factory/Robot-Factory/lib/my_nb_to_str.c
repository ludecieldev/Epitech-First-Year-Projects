/*
** EPITECH PROJECT, 2024
** B_MUL_100_LIL_1_1_myradar_enzo_dubeaurepaire
** File description:
** my_nb_to_str.c
*/

#include "lib.h"

static int len_nbr(int nb)
{
    int cnt = 0;

    if (nb != 0){
        while (nb != 0) {
            nb = nb / 10;
            cnt++;
        }
        return cnt;
    } else
        return 1;
}

static void rec(int nb, int *i, char **str)
{
    if (nb < 0){
        (*str)[0] = '-';
        (*i)++;
        nb *= -1;
    }
    if (nb >= 10){
        rec(nb / 10, i, str);
        rec(nb % 10, i, str);
    }
    if (nb < 10 && nb >= 0){
        (*str)[(*i)] = nb + 48;
        *i = *i + 1;
    }
}

char *my_nb_to_str(int nb)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (len_nbr(nb) + 3));
    rec(nb, &i, &str);
    str[i] = '\0';
    return str;
}
