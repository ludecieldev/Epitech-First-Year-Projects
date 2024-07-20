/*
** EPITECH PROJECT, 2023
** B-MAT-100-LIL-1-1-101pong-alexandre.garbe
** File description:
** errorcase
*/

#include "../../lib/my/my.h"

int is_a_recievable_charactere(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    if (c == '-')
        return 0;
    if (c == ' ')
        return 0;
    return 84;
};

int errorcase(int ac, char **av)
{
    if (ac != 8)
        return 84;
    for (int i = 1; i < 8; i++){
        if (is_a_recievable_charactere(av[i][0]) == 84)
            return 84;
    }
    return 0;
}