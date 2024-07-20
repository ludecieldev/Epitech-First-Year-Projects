/*
** EPITECH PROJECT, 2024
** screen_loop.c
** File description:
** loop for my_rpg
*/

#include "my_rpg.h"

/**
 * @brief Choose the loop for the menu settings or game
 * @param rpg Structure my_rpg
 * @return value
*/
int choose_loop(my_rpg_t *rpg)
{
    int value = 0;
    sfClock *clock = sfClock_create();

    if (!clock)
        return 84;
    while (sfRenderWindow_isOpen(SCREEN_WNDW)) {
        sfRenderWindow_setFramerateLimit(SCREEN_WNDW, rpg->settings->fps);
        if (rpg->loop_value == MENU_LOOP)
            value = menu_loop(rpg);
        if (rpg->loop_value == GAME_LOOP)
            value = game_loop(rpg);
        if (rpg->loop_value == SETTINGS_LOOP)
            value = settings_loop(rpg);
        if (value == 84)
            return 84;
    }
    sfClock_destroy(clock);
    return value;
}
