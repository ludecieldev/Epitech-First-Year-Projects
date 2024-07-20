/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** functions_for_settings
*/

#include "my_rpg.h"

/**
 * @brief Function to set size of rpg
 * @param *data
 * @return void
*/
void resolution_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;

    if (!rpg)
        return;
    sfRenderWindow_setSize(rpg->screen->window, (sfVector2u){1920, 1080});
}

/**
 * @brief Function to set full screen of rpg
 * @param *data
 * @return void
*/
void fullscreen_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    if (!rpg)
        return;
    SETTINGS->fullscreen = !SETTINGS->fullscreen;
    sfRenderWindow_destroy(rpg->screen->window);
    rpg->screen->window = sfRenderWindow_create(mode, "MY_RPG", sfFullscreen,
    NULL);
}

/**
 * @brief Function to back to menu loop
 * @param *data
 * @return void
*/
void back_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;

    if (!rpg)
        return;
    rpg->loop_value = MENU_LOOP;
}
