/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** animation.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void mob_animation_classic(mob_t *mob)
{
    mob->time = sfClock_getElapsedTime(mob->clock);
    mob->seconds = mob->time.microseconds / 1000000.0;
    if (mob->seconds > 0.1) {
        mob->rect.left += 100;
        mob->x += 25;
        if (mob->rect.left >= 400) {
            mob->rect.left = 0;
        }
        if (mob->x >= 1792) {
            mob->x = 0;
        }
        sfSprite_setTextureRect(mob->sprite, mob->rect);
        sfSprite_setPosition(mob->sprite, (sfVector2f){mob->x, mob->y});
        sfClock_restart(mob->clock);
    }
}
