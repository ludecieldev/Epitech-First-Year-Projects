/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** right
*/

#include "my_rpg.h"

/**
 * @brief Function to set the right movement of player
 * @param rpg struct of the my_rpg
 * @return void
*/
void move_right(my_rpg_t *rpg)
{
    int moveSpeed = rpg->game->player->stats[MOVE_SPEED];
    sfColor pixelColor;

    rpg->game->player->rect.top = 495;
    sfSprite_setTextureRect(rpg->game->player->sprite,
        rpg->game->player->rect);
    for (int i = 0; i < moveSpeed; i++) {
        pixelColor = sfImage_getPixel(rpg->game->map,
            rpg->game->player->pos.x + 1, rpg->game->player->pos.y);
        if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0)
            break;
        rpg->game->player->pos.x += 1;
        sfSprite_setPosition(rpg->game->player->sprite,
            (sfVector2f){rpg->game->player->pos.x, rpg->game->player->pos.y});
        sfView_move(rpg->game->view, (sfVector2f){+1, 0});
        game_drawing_part(rpg);
        move_animation(rpg->game->player);
    }
}
