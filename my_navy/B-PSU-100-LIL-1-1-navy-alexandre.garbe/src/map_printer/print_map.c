/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** boat_placer.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

static void cond_break(int i, navy_t *navy)
{
    for (int j = 0; navy->user_map[i][j] != '\0'; j++) {
        mini_printf("%c", navy->user_map[i][j]);
        if (j != 7)
            mini_printf(" ");
    }
}

static void cond_enemy_break(int i, navy_t *navy)
{
    for (int j = 0; navy->enemy_map[i][j] != '\0'; j++) {
        mini_printf("%c", navy->enemy_map[i][j]);
        if (j != 7)
            mini_printf(" ");
    }
}

void print_enemy_map(navy_t *navy)
{
    int i = 0;

    mini_printf("\nenemy navy:\n");
    mini_printf(" |A B C D E F G H\n");
    mini_printf("-+---------------\n");
    while (navy->enemy_map[i] != NULL) {
        mini_printf("%d|", i + 1);
        cond_enemy_break(i, navy);
        mini_printf("\n");
        i++;
    }
}

void print_map(navy_t *navy)
{
    int i = 0;

    mini_printf("\nmy navy:\n");
    mini_printf(" |A B C D E F G H\n");
    mini_printf("-+---------------\n");
    while (navy->user_map[i] != NULL) {
        mini_printf("%d|", i + 1);
        cond_break(i, navy);
        mini_printf("\n");
        i++;
    }
    print_enemy_map(navy);
}
