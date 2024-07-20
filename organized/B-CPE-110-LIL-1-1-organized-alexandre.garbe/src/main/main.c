/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-alexandre.garbe
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/shell.h"

int main(int ac, char **av)
{
    linked_t *begin = NULL;

    if (ac != 1) {
        return (84);
    }
    return (workshop_shell(&begin));
}
