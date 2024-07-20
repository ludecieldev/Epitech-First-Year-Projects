/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** display_items
*/

#include "my_rpg.h"

/**
 * @brief Display an item
 * @param item The item to display
 * @param window The window of the game
 * @return void
*/
void display_items(sfRenderWindow *window, item_t *items)
{
    if (!items)
        return;
    for (int i = 0; items[i].name; i++) {
        sfRenderWindow_drawSprite(window, items[i].sprite, NULL);
    }
}
