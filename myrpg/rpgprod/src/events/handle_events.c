/*
** EPITECH PROJECT, 2024
** handle_events.c
** File description:
** handle all events from the loop program
*/

#include "my_rpg.h"

/**
 * @brief Function to handle the events of the screen
 * @param rpg struct of the game
 * @param event struct of the event
 * @return bool
*/
bool handle_screen_events(my_rpg_t *rpg, sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(SCREEN_WNDW);
    sfVector2f world = sfRenderWindow_mapPixelToCoords(
    SCREEN_WNDW, mouse, SCREEN_VIEW);

    (void)mouse;
    (void)world;
    texts_events(rpg, world);
    screen_events(rpg, event);
    return true;
}
