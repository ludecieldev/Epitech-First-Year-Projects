/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** remove_room
*/

#include "amazed.h"

void remove_room(struct room_s *room, char *name)
{
    struct room_s *tmp = room->next;

    while (tmp != room) {
        if (my_strcmp(tmp->name, name) == 0) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return;
        }
        tmp = tmp->next;
    }
}
