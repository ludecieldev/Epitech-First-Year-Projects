/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** constructor
*/

#include "amazed.h"

room_t *create_list(char *name, int x, int y)
{
    room_t *room = malloc(sizeof(room_t));

    room->name = name;
    room->x = x;
    room->y = y;
    room->isOccupied = false;
    room->next = room;
    room->prev = room;
    room->__add_room__ = &add_room;
    room->__remove_room__ = &remove_room;
    room->__free_room__ = &free_room;
    room->__print_rooms__ = &print_room;
    return room;
}
