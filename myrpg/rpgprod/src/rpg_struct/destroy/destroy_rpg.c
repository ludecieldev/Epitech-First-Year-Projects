/*
** EPITECH PROJECT, 2024
** destroy_rpg.c
** File description:
** destroy struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy texts
 * @param rpg struct of the game
 * @return void
*/
void destroy_settings(my_rpg_t *rpg)
{
    for (int i = 0; i < 6; i++) {
        sfText_destroy(SETTINGS->texts[i].text);
        sfFont_destroy(SETTINGS->texts[i].font);
    }
    for (int i = 0; i < 4; i++) {
        sfText_destroy(SETTINGS->fps_texts[i].text);
        sfFont_destroy(SETTINGS->fps_texts[i].font);
    }
    for (int i = 0; i < 2; i++) {
        sfText_destroy(SETTINGS->vsync_texts[i].text);
        sfFont_destroy(SETTINGS->vsync_texts[i].font);
        sfText_destroy(SETTINGS->fullscreen_texts[i].text);
        sfFont_destroy(SETTINGS->fullscreen_texts[i].font);
    }
    for (int i = 0; i < 3; i++) {
        sfText_destroy(SETTINGS->resolution_texts[i].text);
        sfFont_destroy(SETTINGS->resolution_texts[i].font);
    }
    free(SETTINGS);
}

/**
 * @brief Function to destroy rpg
 * @param rpg struct of the game
 * @return void
*/
void destroy_game(my_rpg_t *rpg)
{
    sfSprite_destroy(rpg->game->background.sprite);
    sfTexture_destroy(rpg->game->background.texture);
    sfView_destroy(rpg->game->view);
    destroy_player(rpg->game->player);
    destroy_enemy(rpg->game->enemy);
    destroy_help(rpg->game->help);
    destroy_pnj(rpg->game->pnj);
    destroy_inventory(rpg->game->inventory);
    sfImage_destroy(rpg->game->map);
    sfSprite_destroy(rpg->game->hover.sprite);
    sfTexture_destroy(rpg->game->hover.texture);
    free(rpg->game->player);
    free(rpg->game->pnj);
    free(rpg->game->enemy);
    free(rpg->game);
}

/**
 * @brief Function to destroy the rpg
 * @param rpg struct of the game
 * @return void
*/
void destroy_rpg(my_rpg_t *rpg)
{
    destroy_cursor(rpg);
    destroy_menu(rpg);
    destroy_texts(rpg);
    destroy_settings(rpg);
    destroy_game(rpg);
    sfView_destroy(rpg->screen->view);
    sfRenderWindow_destroy(rpg->screen->window);
    free_rpg(rpg);
}
