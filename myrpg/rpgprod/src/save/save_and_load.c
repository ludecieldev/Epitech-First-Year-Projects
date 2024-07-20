/*
** EPITECH PROJECT, 2024
** save_and_load.c
** File description:
** function to save & load game
*/

#include "my_rpg.h"

/**
 * @brief Function to save the game
 * @param player struct of the game & filename
 * @return void
*/
void save_player(const player_t *player, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file) {
        perror("Failed to open save file");
        return;
    }
    fprintf(file, "hp %d\n", player->hp);
    fprintf(file, "mana %d\n", player->mana);
    fprintf(file, "level %d\n", player->level);
    fpritnf(file, "xp %d\n", player->xp);
    fprintf(file, "pos_x %f\n", player->pos.x);
    fprintf(file, "pos_y %f\n", player->pos.y);
    fclose(file);
}

/**
 * @brief Function to load the game
 * @param player struct of the game & filename
 * @return void
*/
void load_player(player_t *player, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Failed to open save file");
        return;
    }
    fscanf(file, "hp %d\n", &player->hp);
    fscanf(file, "mana %d\n", &player->mana);
    fscanf(file, "level %d\n", &player->level);
    fscanf(file, "xp %d\n", player->xp);
    fscanf(file, "pos_x %f\n", &player->pos.x);
    fscanf(file, "pos_y %f\n", &player->pos.y);
    sfSprite_setPosition(player->sprite, player->pos);
    fclose(file);
}
