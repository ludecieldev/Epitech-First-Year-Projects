/*
** EPITECH PROJECT, 2024
** create_window
** File description:
** idem
*/

#include "my_rpg.h"

/**
 * @brief Function to create a sfRenderWindow
 * @param width width of the window
 * @param height height of the window
 * @param title title of the window
 * @return sfRenderWindow*
*/
sfRenderWindow *create_window(int width, int height, char *title)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){width, height, 32}, title, sfClose | sfResize, NULL);

    if (window == NULL)
        return NULL;
    return window;
}
