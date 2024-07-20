/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** destroy_item
*/

#include "my_rpg.h"

/**
 * @brief Destroy an item
 * @param item The item to destroy
 * @return void
*/
void destroy_item(item_t *item)
{
    if (item->name)
        free(item->name);
    if (item->sprite)
        sfSprite_destroy(item->sprite);
    if (item->texture)
        sfTexture_destroy(item->texture);
    free(item);
}
