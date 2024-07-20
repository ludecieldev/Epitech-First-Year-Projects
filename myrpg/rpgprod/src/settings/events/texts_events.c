/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** texts_events
*/

#include "my_rpg.h"

/**
 * @brief Function to check is click on settings
 * @param rpg struct of rpg, world vector
 * @return void
*/
void is_clicked_settings(my_rpg_t *rpg, sfVector2f world)
{
    func_for_settings_t settings_action[] = {
        {sfFloatRect_contains, back_function},
        {sfFloatRect_contains, fhd_func},
        {sfFloatRect_contains, hd_func},
        {sfFloatRect_contains, sd_func},
        {sfFloatRect_contains, on_func},
        {sfFloatRect_contains, off_func},
        {sfFloatRect_contains, on_vsync_func},
        {sfFloatRect_contains, off_vsync_func},
        {sfFloatRect_contains, fps_60_func},
        {sfFloatRect_contains, fps_144_func},
        {sfFloatRect_contains, fps_240_func},
        {sfFloatRect_contains, fps_unlimited_func}
    };

    for (int i = 0; i < 12; i++)
        if (settings_action[i].contains(&rpg->settings->rect[i],
            world.x, world.y))
            settings_action[i].action(rpg);
}

/**
 * @brief Function for settings of text events
 * @param rpg struct of rpg and world vector
 * @return void
*/
void settings_texts_events(my_rpg_t *rpg, sfVector2f world,
    UNUSED sfEvent event)
{
    is_over_text(rpg->settings->texts[BACK].text, (sfColor){DARK_RED},
        sfBlack, world);
    for (int i = 0; i < 3; i++)
        is_over_text(rpg->settings->resolution_texts[i].text,
            (sfColor){DARK_RED}, sfBlack, world);
    for (int i = 0; i < 2; i++) {
        is_over_text(rpg->settings->fullscreen_texts[i].text,
            (sfColor){DARK_RED}, sfBlack, world);
        is_over_text(rpg->settings->vsync_texts[i].text, (sfColor){DARK_RED},
            sfBlack, world);
    }
    for (int i = 0; i < 4; i++)
        is_over_text(rpg->settings->fps_texts[i].text, (sfColor){DARK_RED},
            sfBlack, world);
    if (MOUSE_PRESSED(sfMouseLeft))
        is_clicked_settings(rpg, world);
}
