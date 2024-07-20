/*
** EPITECH PROJECT, 2024
** navy
** File description:
** add_boat.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int converter(char c)
{
    if (c == 'A' || c == '1')
        return (0);
    if (c == 'B' || c == '2')
        return (1);
    if (c == 'C' || c == '3')
        return (2);
    if (c == 'D' || c == '4')
        return (3);
    if (c == 'E' || c == '5')
        return (4);
    if (c == 'F' || c == '6')
        return (5);
    if (c == 'G' || c == '7')
        return (6);
    if (c == 'H' || c == '8')
        return (7);
    return (84);
}

int add_boat(boat_t **boats, char *str, int i)
{
    char **tab = str_to_wordarray(str, ':');

    boats[i] = malloc(sizeof(boat_t));
    boats[i]->size = my_getnbr(tab[0]);
    boats[i]->let1 = converter(tab[1][0]);
    boats[i]->num1 = my_getnbr(&tab[1][1]);
    boats[i]->let2 = converter(tab[2][0]);
    boats[i]->num2 = my_getnbr(&tab[2][1]);
    if (boats[i]->let1 == 84 || boats[i]->let2 == 84 || boats[i]->num1 == 84 ||
        boats[i]->num2 == 84 || boats[i]->size == 84)
        return (84);
    return (0);
}
