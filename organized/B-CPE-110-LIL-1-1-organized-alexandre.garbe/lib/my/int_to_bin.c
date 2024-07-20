/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** int_to_bin.c
** Author:
** ludeciel
*/

#include "../../include/shell.h"

int int_to_bin(int nb)
{
    int i = 0;
    int j = 0;
    int bin[32];

    for (; nb > 0; i++) {
        bin[i] = nb % 2;
        nb = nb / 2;
    }
    for (; i >= 0; i--)
        j = j * 10 + bin[i];
    return (j);
}
