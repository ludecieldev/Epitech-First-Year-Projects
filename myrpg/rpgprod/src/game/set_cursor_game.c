/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** set_cursor_game
*/

#include "my_rpg.h"

void set_cursor_game(my_rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords(SCREEN_WNDW,
        mouse_pos, rpg->game->view);

    sfSprite_setPosition(rpg->cursor->sprite, (sfVector2f){world_pos.x,
        world_pos.y});
    if (rpg->loop_value == GAME_LOOP)
        sfSprite_setScale(rpg->cursor->sprite, (sfVector2f){0.03, 0.03});
    else
        sfSprite_setScale(rpg->cursor->sprite, (sfVector2f){0.12, 0.12});
}
