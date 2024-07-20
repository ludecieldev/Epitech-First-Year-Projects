/*
** EPITECH PROJECT, 2024
** handle_events.c
** File description:
** handle all events from the loop program
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the player
 * @param gojo struct of the player
 * @return void
*/
void destroy_player(player_t *gojo)
{
    sfSprite_destroy(gojo->sprite);
    sfTexture_destroy(gojo->texture);
    sfClock_destroy(gojo->clock);
}
