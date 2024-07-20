/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** get_arg_type.c
*/

#include "../../include/my.h"

int is_label_str(char const *str)
{
    char label[] = LABEL_CHARS;
    int found = 0;

    for (int i = 0; str[i]; i++) {
        found = 0;
        for (int j = 0; label[j]; j++)
            found += str[i] == label[j];
        if (!found)
            return 0;
    }
    return 1;
}

int is_label(char *arg)
{
    if (my_strlen(arg) > 2 && arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR &&
        is_label_str(&(arg[2])))
        return 1;
    return 0;
}

int get_arg_type(char *arg)
{
    if (arg[0] == DIRECT_CHAR && my_strlen(arg) > 2 && arg[1] == ':')
        return 2;
    if (arg[0] == DIRECT_CHAR && my_strlen(arg) > 1 &&
        my_str_isnum(&(arg[1])))
        return 2;
    if (arg[0] == 'r' && my_strlen(arg) > 1 && my_str_isnum(&(arg[1])))
        return 1;
    if (my_strlen(arg) > 0 && my_str_isnum(arg))
        return 3;
    return -1;
}
