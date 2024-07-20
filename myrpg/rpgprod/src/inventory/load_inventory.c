/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** load_inventory
*/

#include "my_rpg.h"

/**
 * @brief Load the inventory from a file
 * @param inv The inventory to load
 * @return bool
*/
bool load_inventory(inventory_t *inv)
{
    FILE *file = fopen("save/inventory", "r");

    if (!file)
        return false;
    fread(inv, sizeof(inventory_t), 1, file);
    fclose(file);
    load_items(inv->items);
    return true;
}
