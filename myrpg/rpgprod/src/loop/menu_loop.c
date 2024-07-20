/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** menu_loop
*/

#include "my_rpg.h"

/**
 * @brief Possible events in rpg
 * @param rpg Structure my_rpg
 * @return true
*/
bool rpg_events(my_rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(SCREEN_WNDW, &event))
        if (!handle_screen_events(rpg, &event))
            return false;
    return true;
}

/**
 * @brief menu loop management
 * @param rpg Structure my_rpg
 * @return 0
*/
int menu_loop(my_rpg_t *rpg)
{
    if (rpg_events(rpg) == false)
        return 84;
    set_cursor(rpg);
    if (!sf_drawing_part(rpg))
        return 84;
    return 0;
}
