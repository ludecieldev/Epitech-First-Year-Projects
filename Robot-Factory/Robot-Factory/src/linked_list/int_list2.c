/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex1.c
*/

#include "list.h"

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    int_list_t *new = malloc(sizeof(int_list_t));
    int_list_t *head;

    if (!new)
        return false;
    if (!front_ptr || int_list_get_size(*front_ptr) < position) {
        free(new);
        return false;
    }
    if (!position) {
        free(new);
        return int_list_add_elem_at_front(front_ptr, elem);
    }
    new->value = elem;
    head = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    new->next = head->next;
    head->next = new;
    return true;
}

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new = malloc(sizeof(int_list_t));

    if (!new)
        return false;
    if (!front_ptr) {
        free(new);
        return false;
    }
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}
