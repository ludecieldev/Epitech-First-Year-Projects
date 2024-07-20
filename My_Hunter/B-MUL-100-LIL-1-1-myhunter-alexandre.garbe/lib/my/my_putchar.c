/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** my_putchar.c
*/

#include "my_hunter.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
