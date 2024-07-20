/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** items_detector
*/

#include "my_rpg.h"

/**
 * @brief Add an item to the inventory
 * @param game The game object
 * @param item The item to add
 * @return void
*/
void add_item_to_inventory(game_t *game, item_t *item)
{
    for (int i = 0; i < game->inventory->size; i++) {
        if (game->inventory->items[i].name == NULL) {
            game->inventory->items[i] = *item;
            break;
        }
    }
}

/**
 * @brief Detect if an item is picked
 * @param game The game object
 * @param i The index of the item
 * @return void
*/
static void detect_picked(game_t *game, int i)
{
    if (game->items[i].is_picked == false) {
                game->items[i].is_picked = true;
                add_item_to_inventory(game, &game->items[i]);
            }
}

/**
 * @brief Detect items
 * @param game The game object
 * @return void
*/
void detect_items(game_t *game)
{
    for (int i = 0; game->items[i].name; i++) {
        if (sfFloatRect_contains(&game->items[i].hitbox,
            game->mouse_pos.x, game->mouse_pos.y)) {
            detect_picked(game, i);
        }
    }
}
