/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** funcs
*/

#include "my_rpg.h"

/**
 * @brief Function to set screen in fhd
 * @param rpg struct of rpg
 * @return void
*/
void fhd_func(my_rpg_t *rpg)
{
    if (rpg->settings->fullscreen) {
        rpg->settings->fullscreen = false;
        sfrenderwindow_setfullscreen(SCREEN_WNDW, sfFalse, rpg);
    }
    rpg->settings->resolution = (sfVector2f){1920, 1080};
    sfRenderWindow_setSize(SCREEN_WNDW, (sfVector2u){1920, 1080});
    rpg->settings->resolution_type = RES_1920_1080_TYPE;
}

/**
 * @brief Function to set screen in hd
 * @param rpg struct of rpg
 * @return void
*/
void hd_func(my_rpg_t *rpg)
{
    if (rpg->settings->fullscreen) {
        rpg->settings->fullscreen = false;
        sfrenderwindow_setfullscreen(SCREEN_WNDW, sfFalse, rpg);
    }
    rpg->settings->resolution = (sfVector2f){1280, 720};
    sfRenderWindow_setSize(SCREEN_WNDW, (sfVector2u){1280, 720});
    rpg->settings->resolution_type = RES_1280_720_TYPE;
}

/**
 * @brief Function to set screen in sd
 * @param rpg struct of rpg
 * @return void
*/
void sd_func(my_rpg_t *rpg)
{
    if (rpg->settings->fullscreen) {
        rpg->settings->fullscreen = false;
        sfrenderwindow_setfullscreen(SCREEN_WNDW, sfFalse, rpg);
    }
    rpg->settings->resolution = (sfVector2f){720, 480};
    sfRenderWindow_setSize(SCREEN_WNDW, (sfVector2u){720, 480});
    rpg->settings->resolution_type = RES_720_480_TYPE;
}
