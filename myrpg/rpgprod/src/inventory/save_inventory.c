/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** save_inventory
*/

#include "my_rpg.h"

/**
 * @brief Save the inventory to a file
 * @param inv The inventory to save
 * @return bool
*/
bool save_inventory(inventory_t *inv)
{
    FILE *file = fopen("save/inventory", "w");

    if (!file)
        return false;
    fwrite(inv, sizeof(inventory_t), 1, file);
    fclose(file);
    save_items(inv->items);
    return true;
}
