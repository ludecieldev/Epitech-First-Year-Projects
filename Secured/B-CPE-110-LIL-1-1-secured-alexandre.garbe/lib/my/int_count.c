/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** int_count.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

int int_count(int nb)
{
    int i = 0;

    for (; nb != 0; i++)
        nb /= 10;
    return (i);
}
