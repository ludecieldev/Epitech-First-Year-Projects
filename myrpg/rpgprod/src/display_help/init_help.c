/*
** EPITECH PROJECT, 2024
** init_help.c
** File description:
** init_help functions
*/

#include "my_rpg.h"

void set_zone_for_help(my_rpg_t *rpg)
{
    if (rpg->game->player->pos.y > 725.00)
        sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->game->help->sprite, NULL);
}

void set_func_for_help(help_t *help)
{
    sfSprite_setTexture(help->sprite, help->texture, sfTrue);
    sfSprite_setTextureRect(help->sprite, help->rect);
    sfSprite_setPosition(help->sprite, (sfVector2f){help->pos.x, help->pos.y});
    sfSprite_setScale(help->sprite, (sfVector2f){0.1f, 0.1f});
}

help_t *init_help(void)
{
    help_t *help = calloc(1, sizeof(help_t) + 1);

    if (help == NULL)
        return NULL;
    help->sprite = sfSprite_create();
    help->texture = sfTexture_createFromFile("assets/help/help.png", NULL);
    help->rect = (sfIntRect){0, 0, 1024, 670};
    help->pos = (sfVector2f){125, 800};
    set_func_for_help(help);
    return help;
}
