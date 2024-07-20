/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** hash.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

int mid_square(long long unsigned int nb)
{
    while (int_count(nb) > 6) {
        nb = nb / 10;
    }
    return (unsigned int)nb;
}

int hash(char *key, int len)
{
    unsigned int hash = 5381;
    int c;

    do {
        c = *key;
        *key++;
        hash = ((hash << 5) + hash) + c;
    } while (c);
    return mid_square(hash);
}
