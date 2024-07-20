/*
** EPITECH PROJECT, 2024
** destroy pnj.c
** File description:
** destroy pnj
*/

#include "my_rpg.h"

void destroy_pnj(pnj_t *pnj)
{
    sfSprite_destroy(pnj->sprite);
    sfTexture_destroy(pnj->texture);
}
