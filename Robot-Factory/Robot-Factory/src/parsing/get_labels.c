/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** get_labels.c
*/

#include "../../include/my.h"

int get_param_size(int op, char *param, int *size)
{
    if (get_arg_type(param) == 2 && IS_4BYTES_DIR(op_tab[op].code))
        *size += 4;
    if (get_arg_type(param) == 1)
        *size += 1;
    if (get_arg_type(param) == 3 || (get_arg_type(param) == 2 &&
        (IS_2BYTES_DIR(op_tab[op].code))))
        *size += 2;
    return 0;
}

int increase_size(int op, char **line, int *size)
{
    *size += 1;
    if (HAS_SPEC(op_tab[op].code))
        *size += 1;
    for (int i = 0; i < op_tab[op].nbr_args; i++) {
        if (!is_label(line[i + 1]))
            get_param_size(op, line[i + 1], size);
        else
            *size += 2 + 2 * IS_4BYTES_DIR(op_tab[op].code);
    }
    return 0;
}

static int add_label(char *name, list_t **labels, int position)
{
    labels_t *new_label = malloc(sizeof(labels_t));
    list_t *head = *labels;

    for (; head; head = head->next) {
        if (my_strncmp(name, ((labels_t *)(head->value))->name,
            my_strlen(name) - 1) == 0 && my_strlen(name) - 1 ==
            my_strlen(((labels_t *)(head->value))->name))
            return 1;
    }
    new_label->name = my_strdup(name);
    new_label->name[my_strlen(new_label->name) - 1] = 0;
    new_label->position = position;
    list_add_elem_at_front(labels, new_label);
    return 0;
}

int get_labels_line(char **line, int *size, list_t **labels)
{
    if (line[0][my_strlen(line[0]) - 1] == ':') {
        if (add_label(line[0], labels, *size + 1) == 1)
            return 1;
        line++;
    }
    if (!*line)
        return 0;
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(line[0], op_tab[i].mnemonique) == 0 &&
            my_listlen(line) == op_tab[i].nbr_args + 1)
            increase_size(i, line, size);
    }
    return 0;
}

list_t **get_labels(char ***body)
{
    list_t **labels = malloc(sizeof(list_t *));
    int size = 0;

    *labels = NULL;
    for (int i = 0; body[i]; i++) {
        if (get_labels_line(body[i], &size, labels) == 1)
            return NULL;
    }
    return labels;
}
