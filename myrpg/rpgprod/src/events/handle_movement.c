/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** handle_movements
*/

#include "my_rpg.h"

void handle_movement_events(my_rpg_t *rpg)
{
    sfVector2f move = {0, 0};
    int direction = -1;

    move(&move, &direction, rpg->player.move_speed,
        rpg->delta_time);
    normalize_diagonal_movement(&move);
    apply_movement(&rpg->player, move);
    update_animation_frame(&rpg->player, direction);
}
