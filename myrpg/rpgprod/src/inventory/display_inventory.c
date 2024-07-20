/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** display_inventory
*/

#include "my_rpg.h"

/**
 * @brief Display the inventory and its items
 * @param game The game object
 * @param pos The position of the inventory
 * @param window The window to display the inventory
 * @return void
*/
void display_inventory(game_t *game, sfVector2f pos, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->inventory->sprite, NULL);
    for (int i = 0; i < game->inventory->size; i++) {
        sfSprite_setPosition(game->inventory->items[i].sprite, pos);
        sfRenderWindow_drawSprite(window,
            game->inventory->items[i].sprite, NULL);
        pos.y += 100;
    }
}
