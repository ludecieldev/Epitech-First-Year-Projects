/*
** EPITECH PROJECT, 2024
** set_functions
** File description:
** set functions
*/

#include "my_rpg.h"

/**
 * @brief Function to set the screen
 * @param rpg struct of the game
 * @return void
*/
void sf_set_screen(my_rpg_t *rpg)
{
    sfVector2u size = sfRenderWindow_getSize(SCREEN_WNDW);
    unsigned int width_ = size.x / 2.0f;
    unsigned int height_ = size.y / 2.0f;

    sfView_setCenter(SCREEN->view, (sfVector2f){width_, height_});
    sfView_setSize(SCREEN->view, (sfVector2f){size.x, size.y});
    sfRenderWindow_setView(SCREEN->window, SCREEN->view);
}
