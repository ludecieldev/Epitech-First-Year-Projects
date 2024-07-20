/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** funcs_fps
*/

#include "my_rpg.h"

/**
 * @brief Function for settings 60fps
 * @param rpg struct of rpg
 * @return void
*/

void fps_60_func(my_rpg_t *rpg)
{
    rpg->settings->fps = 60;
    sfRenderWindow_setFramerateLimit(SCREEN_WNDW, 60);
    sfText_setColor(rpg->settings->fps_texts[0].text, sfGreen);
    sfText_setColor(rpg->settings->fps_texts[1].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[2].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[3].text,
        (sfColor){INSIDE_TEXT_COLOR});
}

/**
 * @brief Function for settings 144fps
 * @param rpg struct of rpg
 * @return void
*/
void fps_144_func(my_rpg_t *rpg)
{
    rpg->settings->fps = 144;
    sfRenderWindow_setFramerateLimit(SCREEN_WNDW, 144);
    sfText_setColor(rpg->settings->fps_texts[1].text, sfGreen);
    sfText_setColor(rpg->settings->fps_texts[0].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[2].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[3].text,
        (sfColor){INSIDE_TEXT_COLOR});
}

/**
 * @brief Function for settings 240fps
 * @param rpg struct of rpg
 * @return void
*/
void fps_240_func(my_rpg_t *rpg)
{
    rpg->settings->fps = 240;
    sfRenderWindow_setFramerateLimit(SCREEN_WNDW, 240);
    sfText_setColor(rpg->settings->fps_texts[2].text, sfGreen);
    sfText_setColor(rpg->settings->fps_texts[0].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[1].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[3].text,
        (sfColor){INSIDE_TEXT_COLOR});
}

/**
 * @brief Function for settings unlimited fps
 * @param rpg struct of rpg
 * @return void
*/
void fps_unlimited_func(my_rpg_t *rpg)
{
    rpg->settings->fps = 0;
    sfRenderWindow_setFramerateLimit(SCREEN_WNDW, 0);
    sfText_setColor(rpg->settings->fps_texts[3].text, sfGreen);
    sfText_setColor(rpg->settings->fps_texts[0].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[1].text,
        (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(rpg->settings->fps_texts[2].text,
        (sfColor){INSIDE_TEXT_COLOR});
}
