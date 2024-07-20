/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** add_room
*/

#include "amazed.h"

void add_room(struct room_s *room, struct room_s *new)
{
    if (room == NULL) {
        new->next = new;
        new->prev = new;
    } else {
        new->next = room->next;
        new->prev = room;
        room->next->prev = new;
        room->next = new;
    }
}
