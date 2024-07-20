/*
** EPITECH PROJECT, 2024
** window_draw.c
** File description:
** display on renderwindow
*/

#include "my_rpg.h"

/**
 * @brief Function to draw the texts
 * @param rpg struct of the game
 * @return void
*/
static void draw_texts(my_rpg_t *rpg)
{
    for (int i = 0; i < MENU_NB_TEXTS; i++)
        sfRenderWindow_drawText(SCREEN_WNDW, rpg->menu->texts[i].text, NULL);
}

/**
 * @brief Function to draw the sprites
 * @param rpg struct of the game
 * @return void
*/
static void draw_sprites(my_rpg_t *rpg)
{
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->menu->background.sprite, NULL);
    draw_texts(rpg);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->menu->title.sprite, NULL);
    sfRenderWindow_drawSprite(SCREEN_WNDW, rpg->cursor->sprite, NULL);
}

/**
 * @brief Function to draw the sprites and texts
 * @param rpg struct of the game
 * @return bool
*/
bool sf_drawing_part(my_rpg_t *rpg)
{
    draw_sprites(rpg);
    sfRenderWindow_setView(SCREEN_WNDW, SCREEN_VIEW);
    sfRenderWindow_display(SCREEN_WNDW);
    sfRenderWindow_clear(SCREEN_WNDW, sfBlack);
    return true;
}
