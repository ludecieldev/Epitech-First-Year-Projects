/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex0.c
*/

#include "list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new = malloc(sizeof(int_list_t));
    int_list_t *head;

    if (!new)
        return false;
    if (!front_ptr) {
        free(new);
        return false;
    }
    new->value = elem;
    head = *front_ptr;
    if (!*front_ptr) {
        *front_ptr = new;
        return true;
    }
    for (; head->next; head = head->next);
    head->next = new;
    return true;
}

void int_list_dump(int_list_t *list)
{
    for (; list; list = list->next) {
        my_putnbr(list->value);
        write(1, "\n", 1);
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int size = 0;

    for (; list; list = list->next)
        size++;
    return size;
}

bool int_list_is_empty(int_list_t *list)
{
    if (int_list_get_size(list))
        return false;
    return true;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *head;

    if (!front_ptr || !*front_ptr)
        return;
    while (int_list_get_size(*front_ptr) != 1) {
        for (head = *front_ptr; head && head->next &&
            head->next->next; head = head->next);
        if (head && head->next) {
            free(head->next);
            head->next = NULL;
        }
    }
    free(*front_ptr);
    *front_ptr = NULL;
}
