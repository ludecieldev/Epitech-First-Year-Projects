/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** destroy_inventory
*/

#include "my_rpg.h"

/**
 * @brief Destroy the inventory
 * @param inv The inventory to destroy
 * @return void
*/
void destroy_inventory(inventory_t *inv)
{
    free(inv->items);
    sfSprite_destroy(inv->sprite_inv);
    sfTexture_destroy(inv->texture_inv);
    sfSprite_destroy(inv->sprite_invgem);
    sfTexture_destroy(inv->texture_invgem);
    sfSprite_destroy(inv->sprite_invskull);
    sfTexture_destroy(inv->texture_invskull);
    sfSprite_destroy(inv->sprite_invboth);
    sfTexture_destroy(inv->texture_invboth);
    free(inv);
}
