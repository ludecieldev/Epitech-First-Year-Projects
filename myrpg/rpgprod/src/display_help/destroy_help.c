/*
** EPITECH PROJECT, 2024
** destroy_help.c
** File description:
** destroy all about help
*/

#include "my_rpg.h"

void destroy_help(help_t *help)
{
    sfSprite_destroy(help->sprite);
    sfTexture_destroy(help->texture);
}
