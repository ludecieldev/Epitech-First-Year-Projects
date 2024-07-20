/*
** EPITECH PROJECT, 2024
** Robot-Factory
** File description:
** error_handling.c
** Author:
** ludeciel
*/

#include "../../include/my.h"

static int get_type(char *str)
{
    if (str[0] == DIRECT_CHAR && my_strlen(str) > 2 && str[1] == ':')
        return T_DIR;
    if (str[0] == DIRECT_CHAR && my_strlen(str) > 1 &&
        my_str_isnum(&(str[1])))
        return T_DIR;
    if (str[0] == 'r' && my_strlen(str) > 1 && my_str_isnum(&(str[1])))
        return T_REG;
    if (my_strlen(str) > 0 && my_str_isnum(str))
        return T_IND;
    return 0;
}

static int label_exist(char *name, list_t *labels)
{
    int found = 0;

    for (; labels; labels = labels->next)
        if (my_strcmp(name, ((labels_t *)(labels->value))->name) == 0)
            found = 1;
    return found;
}

int check_instruction(int op, char **line, list_t *labels)
{
    for (int i = 0; i < op_tab[op].nbr_args; i++) {
        if ((get_type(line[i]) & op_tab[op].type[i]) == 0)
            return 84;
        if (is_label(line[i]) && !label_exist(line[i] + 2, labels))
            return 84;
    }
    return 0;
}

int check_line(char **line, list_t *labels)
{
    if (line[0][my_strlen(line[0]) - 1] == ':')
        line++;
    if (!*line)
        return 0;
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(line[0], op_tab[i].mnemonique) == 0 &&
            my_listlen(line) == op_tab[i].nbr_args + 1)
            return check_instruction(i, line + 1, labels);
    }
    return 84;
}

int check_body(char ***body)
{
    list_t **labels = get_labels(body);

    if (!labels)
        return 84;
    for (int i = 0; body[i]; i++)
        if (check_line(body[i], *labels))
            return 84;
    return 0;
}

int check_header(char **name, char **comment)
{
    if (my_strcmp(name[0], ".name") != 0 || my_listlen(name) != 2 ||
        my_strlen(name[1]) > PROG_NAME_LENGTH)
        return 84;
    if (comment && *comment && my_strcmp(comment[0], ".comment")
        == 0 && my_listlen(comment) != 2)
        return 84;
    if (comment && *comment && my_strcmp(comment[0], ".comment")
        == 0 && my_listlen(comment) == 2 &&
        my_strlen(comment[1]) > COMMENT_LENGTH)
        return 84;
    return 0;
}

int error_handling(char ***parse_file)
{
    int err;

    if (!*parse_file)
        return 84;
    err = check_header(parse_file[0], parse_file[1]);
    if (err)
        return 84;
    err = check_body(&(parse_file[1 +
        (parse_file[1] && my_strcmp(".comment\0", parse_file[1][0]) == 0)]));
    return err;
}
