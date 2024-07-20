/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** quit_func
*/

#include "my_rpg.h"

/**
 * @brief Function to quit the game
 * @param data
 * @return void
*/
void quit_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;

    if (!rpg)
        return;
    sfRenderWindow_close(SCREEN_WNDW);
}
