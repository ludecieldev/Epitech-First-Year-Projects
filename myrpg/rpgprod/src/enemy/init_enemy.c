/*
** EPITECH PROJECT, 2024
** init_enemy.c
** File description:
** init_enemy function
*/

#include "my_rpg.h"

/**
 * @brief Function to set the animation of the mob
 * @param mob struct of the enemy
 * @return void
*/
void enemy_animation(enemy_t *mob)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(mob->clock)) > 100) {
        mob->rect.left += 64;
        if (mob->rect.left >= 192)
            mob->rect.left = 0;
        sfClock_restart(mob->clock);
    }
    sfSprite_setTextureRect(mob->sprite, mob->rect);
}

/**
 * @brief Function to set the abilities of the mob
 * @param mob struct of the mob
 * @return void
*/
void set_func_for_mob(enemy_t *mob)
{
    sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
    sfSprite_setTextureRect(mob->sprite, mob->rect);
    sfSprite_setPosition(mob->sprite, (sfVector2f){mob->pos.x, mob->pos.y});
}

/**
 * @brief Function to init the enemy
 * @param mob struct of the enemy
 * @return void
*/
enemy_t *init_enemy(void)
{
    enemy_t *mob = calloc(1, sizeof(enemy_t) + 1);

    if (mob == NULL)
        return NULL;
    mob->clock = sfClock_create();
    mob->sprite = sfSprite_create();
    mob->texture = sfTexture_createFromFile("assets/enemy/curse.png", NULL);
    mob->rect = (sfIntRect){0, 0, 64, 61};
    mob->hp = 500;
    mob->hitbox = (sfFloatRect){0, 0, 64, 61};
    mob->pos = (sfVector2f){450, 510};
    set_func_for_mob(mob);
    return mob;
}
