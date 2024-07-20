/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** load_items
*/

#include "my_rpg.h"

/**
 * @brief Load the items from a file
 * @param items The items to load
 * @return bool
*/
bool load_items(item_t *items)
{
    FILE *file = fopen("save/items", "r");

    if (!file)
        return false;
    fread(items, sizeof(item_t), 1, file);
    fclose(file);
    return true;
}
