/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** help.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

void help(void)
{
    mini_printf("USAGE\n");
    mini_printf("     ./navy [first_player_pid] navy_positions\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("     first_player_pid: only for the 2nd player. ");
    mini_printf("pid of the first player.\n");
    mini_printf("     navy_positions: file representing the positions ");
    mini_printf("of the ships.\n");
}
