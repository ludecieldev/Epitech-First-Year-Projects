/*
** EPITECH PROJECT, 2024
** destroy_rpg.c
** File description:
** destroy struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the cursor
 * @param rpg struct of the game
 * @return void
*/
void destroy_cursor(my_rpg_t *rpg)
{
    sfSprite_destroy(rpg->cursor->sprite);
    sfTexture_destroy(rpg->cursor->texture);
}
