/*
** EPITECH PROJECT, 2024
** update_hud.c
** File description:
** //
*/

#include "my_rpg.h"

/**
 * @brief Function to update the hud
 * @param hud struct of the hud
 * @param player struct of the player
 * @return void
*/
void update_hud(hud_t *hud, player_t *player)
{
    char buffer[128];
    float xp_ratio;

    sprintf(buffer, "Niveau: %d", player->level);
    sfText_setString(hud->niveau, buffer);
    xp_ratio = (float)player->xp / player->xp_next_lvl;
    sfRectangleShape_setSize(hud->xp_bar, (sfVector2f){200 * xp_ratio, 20});
    sprintf(buffer, "%d / %d XP", player->xp, player->xp_next_lvl);
    sfText_setString(hud->xp_text, buffer);
}
