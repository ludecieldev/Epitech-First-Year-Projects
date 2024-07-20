/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** my_swap.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
