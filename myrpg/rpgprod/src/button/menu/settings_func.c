/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** settings_func
*/

#include "my_rpg.h"

/**
 * @brief Function to go to settings
 * @param data
 * @return void
*/
void settings_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;

    if (!rpg)
        return;
    sfRenderWindow_setTitle(SCREEN_WNDW, "My_RPG - Settings");
    rpg->loop_value = SETTINGS_LOOP;
}
