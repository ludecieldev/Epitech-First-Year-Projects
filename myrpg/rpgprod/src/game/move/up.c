/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** up
*/

#include "my_rpg.h"

/**
 * @brief Function to animate the up movement of player
 * @param player struct of the player
 * @return void
*/
void move_animation(player_t *player)
{
    if (sfTime_asMicroseconds
    (sfClock_getElapsedTime(player->clock)) > 100000) {
        player->rect.left += 384;
        if (player->rect.left >= 384 * 3)
            player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
}

/**
 * @brief Function to set the up movement of player
 * @param rpg struct of the my_rpg
 * @return void
*/
void move_up(my_rpg_t *rpg)
{
    int moveSpeed = rpg->game->player->stats[MOVE_SPEED];
    sfColor pixelColor;

    rpg->game->player->rect.top = 495 * 3 + 50;
    sfSprite_setTextureRect(rpg->game->player->sprite,
        rpg->game->player->rect);
    for (int i = 0; i < moveSpeed; i++) {
        pixelColor = sfImage_getPixel(rpg->game->map,
            rpg->game->player->pos.x, rpg->game->player->pos.y - 1);
        if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0)
            break;
        rpg->game->player->pos.y -= 1;
        sfSprite_setPosition(rpg->game->player->sprite,
            (sfVector2f){rpg->game->player->pos.x, rpg->game->player->pos.y});
        sfView_move(rpg->game->view, (sfVector2f){0, -1});
        game_drawing_part(rpg);
        move_animation(rpg->game->player);
    }
}
