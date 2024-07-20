/*
** EPITECH PROJECT, 2024
** destroy_rpg.c
** File description:
** destroy struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the menu
 * @param rpg struct of the game
 * @return void
*/
void destroy_menu(my_rpg_t *rpg)
{
    sfSprite_destroy(rpg->menu->background.sprite);
    sfTexture_destroy(rpg->menu->background.texture);
    sfSprite_destroy(rpg->menu->title.sprite);
    sfTexture_destroy(rpg->menu->title.texture);
}
