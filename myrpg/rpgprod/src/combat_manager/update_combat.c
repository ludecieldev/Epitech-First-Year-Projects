/*
** EPITECH PROJECT, 2024
** rpg-prod
** File description:
** update_combat
*/

#include "my_rpg.h"

/**
 * @brief Function to update the combat
 * @param player struct of the player
 * @param enemy struct of the enemy
 * @return void
*/
void update_combat(player_t *player, enemy_t *enemy)
{
    player->hitbox = sfSprite_getGlobalBounds(player->sprite);
    enemy->hitbox = sfSprite_getGlobalBounds(enemy->sprite);
    if (sfFloatRect_intersects(&player->hitbox, &enemy->hitbox, NULL)) {
        player->hp -= enemy->damage;
        enemy->hp -= player->damage;
        if (enemy->hp <= 0) {
            player->xp += 50;
            enemy->hp = 50;
            enemy->pos = (sfVector2f){600, 100};
            sfSprite_setPosition(enemy->sprite, enemy->pos);
        }
        if (player->xp >= player->xp_next_lvl) {
            player->level++;
            player->xp = 0;
            player->xp_next_lvl += 100;
            player->hp += 20;
            player->damage += 5;
        }
    }
}
