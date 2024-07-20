/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** inventory_detector
*/

#include "my_rpg.h"

/**
 * @brief Initialize the inventory
 * @param game The game object where the inventory is stored
 * @return void
*/
void init_inventory(game_t *game)
{
    inventory_t *inv;

    if (access("save/inventory", F_OK) != -1) {
        inv = create_inventory();
        load_inventory(inv);
    } else {
        inv = create_inventory();
    }
    game->inventory = inv;
}
