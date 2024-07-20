/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr.c
*/

#include "my_hunter.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
        if (nb >= 10){
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) +48);
        count ++;
        return (count + 2);
    }
    if (nb >= 0){
        if (nb >= 10){
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + 48);
        count++;
        return (count + 2);
    }
}
