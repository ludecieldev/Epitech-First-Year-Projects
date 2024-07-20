/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** screen_events
*/

#include "my_rpg.h"

/**
 * @brief Function to handle screen events
 * @param rpg struct of the game
 * @param event event of the game
 * @return void
*/
void screen_events(my_rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(SCREEN_WNDW);
}
