/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex6_2.c
*/

#include "list.h"

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_front((list_t *)queue);
}
