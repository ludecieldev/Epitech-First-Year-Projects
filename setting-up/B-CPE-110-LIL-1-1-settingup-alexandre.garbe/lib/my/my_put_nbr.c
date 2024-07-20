/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr.c
*/

#include "settingup.h"

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
        if (nb >= 10){
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) +48);
    }
    if (nb >= 0){
        if (nb >= 10){
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
