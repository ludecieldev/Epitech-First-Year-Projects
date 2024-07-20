/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** score_management.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void score_management(window_t *window, mob_t *mob)
{
    sfVector2f score_pos = {0, 0};
    char *score_str = my_itoa(mob->nb_hit);

    sfText_setString(window->score, score_str);
    sfText_setFont(window->score, window->font);
    sfText_setCharacterSize(window->score, 50);
    sfText_setPosition(window->score, score_pos);
    sfRenderWindow_drawText(window->window, window->score, NULL);
}
