/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

int main(int av, char **ac)
{
    if (av == 2 && ac[1][0] == '-' && ac[1][1] == 'h') {
        mini_printf("Welcome to My_Hunter !\n");
        mini_printf("You have to kill the mob by clicking on it !\n");
        mini_printf("Good luck and enjoy ! ;)\n");
        mini_printf("USAGE\n");
        mini_printf("    ./my_hunter\n");
        mini_printf("OPTIONS\n");
        mini_printf("    -h : print the usage and quit.\n");
        return (0);
    } else if (av == 1) {
        render_window();
        return (0);
    }
}
