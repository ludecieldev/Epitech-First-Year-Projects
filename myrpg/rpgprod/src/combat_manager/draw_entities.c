/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** draw_entities
*/

#include "my_rpg.h"

/**
 * @brief Function to draw the entities
 * @param window window of the game
 * @param player struct of the player
 * @param enemy struct of the enemy
 * @return void
*/
void draw_entities(sfRenderWindow *window, player_t *player, enemy_t *enemy)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
}
