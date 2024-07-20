/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** game_events
*/

#include "my_rpg.h"

/**
 * @brief Function to set the events ingame
 * @param rpg struct of the rgp
 * @return true
*/
bool game_events(my_rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(SCREEN_WNDW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(SCREEN_WNDW);
        moves_keys_events(rpg);
        check_inventory_key(rpg, event);
    }
    return true;
}

void check_inventory_key(my_rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE) {
        toggle_inventory_display(rpg->game->inventory);
    }
}
