/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** print_room
*/

#include "amazed.h"

void print_room(room_t *room)
{
    room_t *tmp = room;

    while (tmp) {
        my_putstr(tmp->name);
        my_putchar(' ');
        my_put_nbr(tmp->x);
        my_putchar(' ');
        my_put_nbr(tmp->y);
        my_putchar(' ');
        if (tmp->isOccupied)
            my_putstr(" Occupied");
        else
            my_putstr(" Free");
        my_putchar('\n');
        tmp = tmp->next;
    }
}
