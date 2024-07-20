/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** create_item
*/

#include "my_rpg.h"

/**
 * @brief Get a new id
 * @return int The new id
 */
int new_id(void)
{
    static int id = 0;

    id++;
    return id;
}

/**
 * @brief Create an item
 * @param path The path to the item's texture
 * @param name The name of the item
 * @param type The type of the item
 * @return item_t* The created item
 */
item_t *create_item(char *path, char *name, int type)
{
    item_t *item = calloc(1, sizeof(item_t) + 1);

    if (!item)
        return NULL;
    item->name = strdup(name);
    item->item_id = new_id();
    item->type = type;
    item->texture = sfTexture_createFromFile(path, NULL);
    item->sprite = sfSprite_create();
    if (!item->texture || !item->sprite)
        return NULL;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    return item;
}
