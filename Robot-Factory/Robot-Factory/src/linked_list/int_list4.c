/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex3.c
*/

#include "list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *tmp;

    if (!front_ptr || !*front_ptr)
        return false;
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *head;

    if (!front_ptr || !*front_ptr)
        return false;
    if (int_list_get_size(*front_ptr) == 1)
        return int_list_del_elem_at_front(front_ptr);
    for (head = *front_ptr; head->next && head->next->next; head = head->next);
    free(head->next);
    head->next = NULL;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *head;
    int_list_t *new_next;

    if (!front_ptr || !*front_ptr || position >= int_list_get_size(*front_ptr))
        return false;
    if (!position)
        return int_list_del_elem_at_front(front_ptr);
    head = *front_ptr;
    for (unsigned int i = 1; i < position; i++)
        head = head->next;
    new_next = head->next->next;
    free(head->next);
    head->next = new_next;
    return true;
}
