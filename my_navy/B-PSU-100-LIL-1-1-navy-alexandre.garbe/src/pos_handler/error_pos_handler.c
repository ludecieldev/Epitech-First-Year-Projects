/*
** EPITECH PROJECT, 2024
** navy
** File description:
** error_pos_handler.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

static int is_a_good_char(char c)
{
    char recievable_char[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
                            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', ':',
                            '\n', '\0'};

    for (int i = 0; i < 20; i++) {
        if (c == recievable_char[i])
            return (0);
    }
    return (1);
}

int check_size(char *str)
{
    char **array = str_to_wordarray(str, ':');

    if (my_getnbr(array[0]) > 5 || my_getnbr(array[0]) < 2)
        return (1);
    if (my_getnbr(array[1]) > 8 || my_getnbr(array[1]) < 1
    || my_getnbr(array[2]) > 8 || my_getnbr(array[2]) < 1)
        return (1);
    if (my_getnbr(array[1]) > my_getnbr(array[2]) || array[1][0] > array[2][0])
        return (1);
    if (array[1][0] != array[2][0] && array[1][1] != array[2][1])
        return (1);
    if (array[1][0] == array[2][0] && array[1][1] == array[2][1])
        return (1);
    return (0);
}

int error_pos_handling(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (is_a_good_char(str[i]) == 1)
            return (1);
        if (check_size(str) == 1)
            return (1);
    }
    return (0);
}
