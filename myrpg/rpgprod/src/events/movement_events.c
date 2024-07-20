/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** movement_events
*/

#include "my_rpg.h"

void move(sfVector2f *move, int *direction, float move_speed, float delta_time)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move->y -= move_speed * delta_time;
        *direction = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move->y += move_speed * delta_time;
        *direction = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move->x -= move_speed * delta_time;
        *direction = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        move->x += move_speed * delta_time;
        *direction = 3;
    }
}

void normalize_diagonal_movement(sfVector2f *move)
{
    if (move->x != 0 && move->y != 0) {
        move->x /= sqrt(2);
        move->y /= sqrt(2);
    }
}

void apply_movement(player_t *player, sfVector2f move)
{
    player->pos.x += move.x;
    player->pos.y += move.y;
    sfSprite_setPosition(player->sprite, player->pos);
}

void update_frame_rect(player_t *player)
{
    if (sfClock_getElapsedTime(player->clock).microseconds > 100000) {
        player->rect.left += 300;
        if (player->rect.left >= 1200) {
            player->rect.left = 0;
        }
        sfClock_restart(player->clock);
    }
}

void update_animation_frame(player_t *player, int direction)
{
    if (direction == -1) {
        return;
    }
    player->rect.top = direction * 360;
    update_frame_rect(player);
    sfSprite_setTextureRect(player->sprite, player->rect);
}
