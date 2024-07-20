/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** play_func
*/

#include "my_rpg.h"

/**
 * @brief Function to play the game
 * @param data
 * @return void
*/
void play_func(void *data)
{
    my_rpg_t *rpg = (my_rpg_t *)data;

    if (!rpg)
        return;
    sfRenderWindow_setTitle(SCREEN_WNDW, "My_RPG - Pov: tu manges les doigts "
        "de sukuna un par un" " (il est bon ce doigt)");
    rpg->loop_value = GAME_LOOP;
    choose_loop(rpg);
}
