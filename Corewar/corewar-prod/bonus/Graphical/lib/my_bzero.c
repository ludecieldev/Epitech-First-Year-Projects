/*
** EPITECH PROJECT, 2023
** B_MUL_100_LIL_1_1_myradar_enzo_dubeaurepaire
** File description:
** my_bzero.c
*/

#include "lib.h"

void my_bzero(char *str, long size)
{
    for (int i = 0; str[i] && i < size; i++)
        str[i] = 0;
}
