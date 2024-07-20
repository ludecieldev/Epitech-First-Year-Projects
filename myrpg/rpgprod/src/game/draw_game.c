/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** draw_game
*/

#include "my_rpg.h"

void drawing(my_rpg_t *rpg)
{
    set_cursor_game(rpg);
    sfRenderWindow_clear(SCREEN_WNDW, sfBlack);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->background.sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->cursor->sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->player->sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->enemy->sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->hover.sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->pnj->sprite, NULL);
}

void drawing_two(my_rpg_t *rpg)
{
    set_zone_for_help(rpg);
    enemy_animation(rpg->game->enemy);
    sfRenderWindow_setView(SCREEN_WNDW, rpg->game->view);
    sfRenderWindow_display(SCREEN_WNDW);
}

void draw_inventory(my_rpg_t *rpg, inventory_t *inventory)
{
    if (inventory->is_both_picked == true) {
        sfRenderWindow_drawSprite(SCREEN_WNDW, inventory->sprite_invboth, NULL);
        return;
    }
    if (inventory->is_gem_picked == true) {
        sfRenderWindow_drawSprite(SCREEN_WNDW, inventory->sprite_invgem, NULL);
        return;
    }
    if (inventory->is_skull_picked == true) {
        sfRenderWindow_drawSprite(SCREEN_WNDW, inventory->sprite_invskull, NULL);
        return;
    }
    if (inventory->is_empty == true) {
        sfRenderWindow_drawSprite(SCREEN_WNDW, inventory->sprite_inv, NULL);
        return;
    }
}

/**
 * @brief Function to draw the game in rpg_loop
 * @param rpg struct of the my_rpg
 * @return void
*/
void game_drawing_part(my_rpg_t *rpg)
{
    drawing(rpg);
    if (rpg->game->inventory->is_visible == true)
        draw_inventory(rpg, rpg->game->inventory);
    drawing_two(rpg);
}
