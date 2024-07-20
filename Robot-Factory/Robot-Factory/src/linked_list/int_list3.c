/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex2.c
*/

#include "list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    if (!list)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (!list)
        return 0;
    if (int_list_get_size(list) == 1)
        return list->value;
    for (; list->next; list = list->next);
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    if (!list || int_list_get_size(list) <= position)
        return 0;
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return list->value;
}
