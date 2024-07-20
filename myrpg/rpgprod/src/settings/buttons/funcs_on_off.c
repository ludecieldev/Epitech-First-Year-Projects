/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** funcs_on_off
*/

#include "my_rpg.h"

/**
 * @brief Function for setting full screen
 * @param rpg struct of rpg, window of game and bool of fullscreen
 * @return void
*/
void sfrenderwindow_setfullscreen(sfRenderWindow *window, sfBool fullscreen,
    my_rpg_t *rpg)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    if (!rpg)
        return;
    rpg->settings->fullscreen = fullscreen;
    sfRenderWindow_destroy(window);
    if (fullscreen)
        window = sfRenderWindow_create(mode, "MY_RPG", sfFullscreen, NULL);
    else {
        mode.height = rpg->settings->resolution.y;
        mode.width = rpg->settings->resolution.x;
        window = sfRenderWindow_create(mode, "MY_RPG", sfClose,
            NULL);
    }
    rpg->screen->window = window;
}

/**
 * @brief Function to set fullscreen on
 * @param rpg struct of rpg
 * @return void
*/
void on_func(my_rpg_t *rpg)
{
    rpg->settings->fullscreen = true;
    sfrenderwindow_setfullscreen(SCREEN_WNDW, sfTrue, rpg);
}

/**
 * @brief Function to set fullscreen off
 * @param rpg struct of rpg
 * @return void
*/
void off_func(my_rpg_t *rpg)
{
    rpg->settings->fullscreen = false;
    sfrenderwindow_setfullscreen(SCREEN_WNDW, sfFalse, rpg);
}

/**
 * @brief Function to set vsync on
 * @param rpg struct of rpg
 * @return void
*/
void on_vsync_func(my_rpg_t *rpg)
{
    rpg->settings->vsync = true;
    sfRenderWindow_setVerticalSyncEnabled(SCREEN_WNDW, sfTrue);
}

/**
 * @brief Function to set vsync off
 * @param rpg struct of rpg
 * @return void
*/
void off_vsync_func(my_rpg_t *rpg)
{
    rpg->settings->vsync = false;
    sfRenderWindow_setVerticalSyncEnabled(SCREEN_WNDW, sfFalse);
}
