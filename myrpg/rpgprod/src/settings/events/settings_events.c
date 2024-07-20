/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** settings_events
*/

#include "my_rpg.h"

/**
 * @brief function to manage events in settings
 * @param rpg struct of rpg
 * @return bool
*/
bool settings_events(my_rpg_t *rpg)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
        SCREEN_WNDW, mouse, SCREEN_VIEW);

    while (sfRenderWindow_pollEvent(SCREEN_WNDW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(SCREEN_WNDW);
        settings_texts_events(rpg, world, event);
    }
    return true;
}
