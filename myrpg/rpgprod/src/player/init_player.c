/*
** EPITECH PROJECT, 2024
** handle_events.c
** File description:
** handle all events from the loop program
*/

#include "my_rpg.h"

/**
 * @brief Function to set the abilities of the player
 * @param gojo struct of the player
 * @return void
*/
void set_func_for_player(player_t *gojo)
{
    sfSprite_scale(gojo->sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setTexture(gojo->sprite, gojo->texture, sfTrue);
    sfSprite_setTextureRect(gojo->sprite, gojo->rect);
    sfSprite_setPosition(gojo->sprite, (sfVector2f){gojo->pos.x, gojo->pos.y});
}

/**
 * @brief Function to init the player
 * @param gojo struct of the player
 * @return void
*/
player_t *init_player(void)
{
    player_t *gojo = calloc(1, sizeof(player_t) + 1);

    if (gojo == NULL)
        return NULL;
    gojo->pos = (sfVector2f){245, 800};
    gojo->clock = sfClock_create();
    gojo->texture = sfTexture_createFromFile("assets/player/gojo.png", NULL);
    gojo->rect = (sfIntRect){0, 0, 384, 495};
    gojo->sprite = sfSprite_create();
    gojo->hitbox = (sfFloatRect){gojo->pos.x, gojo->pos.y, 384.5, 495};
    gojo->stats[HP] = 500;
    gojo->stats[MOVE_SPEED] = 15;
    gojo->stats[DAMAGE] = 50;
    gojo->stats[MANA] = 0;
    gojo->stats[LEVEL] = 1;
    gojo->stats[XP] = 0;
    gojo->stats[XP_NEXT_LVL] = 100;
    set_func_for_player(gojo);
    return gojo;
}
