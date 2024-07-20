/*
** EPITECH PROJECT, 2024
** set_cursor.c
** File description:
** set the cursor
*/

#include "my_rpg.h"

/**
 * @brief Function to set the cursor
 * @param rpg struct of the game
 * @return bool
*/
bool set_cursor(my_rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
    SCREEN_WNDW, mouse, SCREEN_VIEW);

    sfSprite_setPosition(rpg->cursor->sprite, world);
    sfRenderWindow_setMouseCursorVisible(SCREEN_WNDW, sfFalse);
    return true;
}
