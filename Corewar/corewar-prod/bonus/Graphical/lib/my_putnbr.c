/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Placeholder
*/

#include "lib.h"

void my_putnbr(long nb)
{
    char c = 0;

    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    if (nb < 10 && nb >= 0) {
        c = nb + 48;
        write(1, &c, 1);
    }
}
