/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr.c
*/

#include "../../include/my_radar.h"

int my_putstr(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
        count ++;
    }
    return (count);
}
