/*
** EPITECH PROJECT, 2024
** init_pnj.c
** File description:
** init_pnj function
*/

#include "my_rpg.h"

void set_func_for_pnj(pnj_t *pnj)
{
    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setTextureRect(pnj->sprite, pnj->rect);
    sfSprite_setPosition(pnj->sprite, (sfVector2f){pnj->pos.x, pnj->pos.y});
    sfSprite_setScale(pnj->sprite, (sfVector2f){0.06, 0.06});
}

pnj_t *init_pnj(void)
{
    pnj_t *pnj = calloc(1, sizeof(pnj_t));

    if (pnj == NULL)
        return NULL;
    pnj->sprite = sfSprite_create();
    pnj->texture = sfTexture_createFromFile("assets/pnj/pnj.png", NULL);
    pnj->rect = (sfIntRect){0, 0, 273, 449};
    pnj->pos = (sfVector2f){220, 695};
    set_func_for_pnj(pnj);
    return pnj;
}
