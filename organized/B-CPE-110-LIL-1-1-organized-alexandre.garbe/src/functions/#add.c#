/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** add.c
** Author:
** ludeciel
*/

#include "../../include/shell.h"

static int add_checker(char *str)
{
    if (my_strcmp(str, "WIRE") == 0 ||
        my_strcmp(str, "SENSOR") == 0 ||
        my_strcmp(str, "PROCESSOR") == 0 ||
        my_strcmp(str, "DEVICE") == 0 ||
        my_strcmp(str, "ACTUATOR") == 0)
        return 0;
    return 1;
}

int find_id(void *data)
{
    linked_t **list = data;
    linked_t *tmp = *list;
    int id = -1;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->id > id)
            id = tmp->id;
    }
    return id;
}

void printer(linked_t *add)
{
    mini_printf("%s n°%d - %c%s%c added.\n",
        add->type, add->id, '"', add->name, '"');
}

static int arg_checker(char **args, int i)
{
    if (args[i] == NULL || args[i + 1] == NULL ||
        add_checker(args[i]) == 1)
        return 1;
    return 0;
}

int add(void *data, char **args)
{
    linked_t **list = data;
    linked_t *add;

    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i]; i++) {
        if (arg_checker(args, i) == 1)
            return 84;
        add = malloc(sizeof(linked_t));
        add->id = find_id(list) + 1;
        add->type = my_strdup(args[i]);
        i++;
        add->name = my_strdup(args[i]);
        printer(add);
        add->next = *list;
        *list = add;
    }
    return 0;
}
