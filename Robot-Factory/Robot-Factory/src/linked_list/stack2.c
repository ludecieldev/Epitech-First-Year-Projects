/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex5_2.c
*/

#include "list.h"

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
