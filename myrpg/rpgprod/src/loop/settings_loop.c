/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** settings_loop
*/

#include "my_rpg.h"

/**
 * @brief draw settings loop
 * @param rpg Structure my_rpg
 * @return true
*/
bool settings_drawing_part(my_rpg_t *rpg)
{
    change_text_color(rpg, sfYellow);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->menu->background.sprite, NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(SCREEN_WNDW,
                                rpg->settings->texts[i].text, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(SCREEN_WNDW, rpg->TEXT_RESOLUTIONS, NULL);
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawText(SCREEN_WNDW, rpg->TEXT_FULLSCREENS, NULL);
        sfRenderWindow_drawText(SCREEN_WNDW, VSYNC_TEXTS[i].text, NULL);
    }
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(SCREEN_WNDW, FPS_TEXTS[i].text, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->cursor->sprite, NULL);
    sfRenderWindow_setView(SCREEN_WNDW, SCREEN_VIEW);
    sfRenderWindow_display(SCREEN_WNDW);
    sfRenderWindow_clear(SCREEN_WNDW, sfBlack);
    return true;
}

/**
 * @brief settings loop management
 * @param rpg Structure my_rpg
 * @return 0
*/
int settings_loop(my_rpg_t *rpg)
{
    if (settings_events(rpg) == false)
        return 84;
    set_cursor(rpg);
    if (!settings_drawing_part(rpg))
        return 84;
    return 0;
}
