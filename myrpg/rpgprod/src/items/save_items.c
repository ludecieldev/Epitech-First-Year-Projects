/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** save_items
*/

#include "my_rpg.h"

/**
 * @brief Save the items to a file
 * @param items The items to save
 * @return bool
*/
bool save_items(item_t *items)
{
    FILE *file = fopen("save/items", "w");

    if (!file)
        return false;
    fwrite(items, sizeof(item_t), 1, file);
    fclose(file);
    return true;
}
