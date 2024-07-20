/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 05
*/

#ifndef STACK_H
    #define STACK_H
    #include "l_list.h"

typedef list_t stacks_t;
unsigned int stack_get_size(stacks_t *stack);
bool stack_is_empty(stacks_t *stack);
bool stack_push(stacks_t **stack_ptr, void *elem);
bool stack_pop(stacks_t **stack_ptr);
void stack_clear(stacks_t **stack_ptr);
void *stack_top(stacks_t *stack);
#endif
