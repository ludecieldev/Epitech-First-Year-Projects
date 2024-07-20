/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** is_a_number.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int is_a_number(char c)
{
    return ((c < '0' || c > '9') ? 1 : 0);
}
