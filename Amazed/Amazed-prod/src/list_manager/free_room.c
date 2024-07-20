/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** free_room
*/

#include "amazed.h"

void free_room(struct room_s *room)
{
    struct room_s *tmp = room->next;
    struct room_s *next = NULL;

    while (tmp != room) {
        next = tmp->next;
        free(tmp->name);
        free(tmp);
        tmp = next;
    }
    free(room->name);
    free(room);
}
