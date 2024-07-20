/*
** EPITECH PROJECT, 2024
** destroy_enemy.c
** File description:
** destroy all about enemy
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the enemy
 * @param mob struct of the enemy
 * @return void
*/
void destroy_enemy(enemy_t *mob)
{
    sfSprite_destroy(mob->sprite);
    sfTexture_destroy(mob->texture);
    sfClock_destroy(mob->clock);
}
