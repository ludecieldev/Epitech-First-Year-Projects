/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** disp.c
** Author:
** ludeciel
*/

#include "../../include/shell.h"

int disp(void *data, char **args)
{
    linked_t **list = data;
    linked_t *tmp = *list;

    for (; tmp != NULL; tmp = tmp->next) {
        mini_printf("%s n°%d - %c%s%c\n",
            tmp->type, tmp->id, '"', tmp->name, '"');
    }
    return (0);
}
