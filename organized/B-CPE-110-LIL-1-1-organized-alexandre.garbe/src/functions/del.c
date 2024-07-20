/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** del.c
** Author:
** ludeciel
*/

#include "../../include/shell.h"

static void printer(linked_t *nodeToDelete)
{
    mini_printf("%s n°%d - %c%s%c deleted.\n",
                nodeToDelete->type, nodeToDelete->id, '"'
                , nodeToDelete->name, '"');
}

static int check_first(linked_t **list, int target, linked_t *tmp)
{
    if (*list == NULL)
        return 84;
    while (*list != NULL && (*list)->id == target) {
        tmp = *list;
        printer(tmp);
        *list = (*list)->next;
        free(tmp);
    }
    return 0;
}

static int del_func(linked_t **list, int target)
{
    linked_t *tmp = *list;
    linked_t *nodeToDelete = NULL;

    if (check_first(list, target, tmp) == 84)
        return 84;
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->next->id == target) {
            nodeToDelete = tmp->next;
            printer(nodeToDelete);
            tmp->next = nodeToDelete->next;
            free(nodeToDelete);
            return 0;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL)
        return 0;
    return 84;
}

int del(void *data, char **args)
{
    linked_t **list = data;
    int target;

    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i]; i++) {
        if (args[i] < 0 || args[i] == NULL)
            return 84;
        target = my_getnbr(args[i]);
        if (del_func(list, target) == 84)
            return 84;
    }
    return 0;
}
