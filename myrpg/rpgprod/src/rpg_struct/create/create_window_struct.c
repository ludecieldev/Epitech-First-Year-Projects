/*
** EPITECH PROJECT, 2024
** create_rpg.c
** File description:
** create struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to verify if the window struct is correctly created
 * @param window the window struct
 * @return window_t* the window struct
*/
window_t *verif_window_struct(window_t *window)
{
    if (window->window == NULL) {
        sfView_destroy(window->view);
        free(window);
        return NULL;
    } else if (window->view == NULL) {
        sfRenderWindow_destroy(window->window);
        free(window);
        return NULL;
    }
    return window;
}

/**
 * @brief Function to create a window struct
 * @param width width of the window
 * @param height height of the window
 * @param title title of the window
 * @return window_t* the window struct
*/
window_t *create_window_struct(int width, int height, char *title)
{
    window_t *window = calloc(1, sizeof(window_t) + 1);

    if (window == NULL)
        return NULL;
    window->window = create_window(width, height, title);
    window->view = create_view();
    window->width = width;
    window->height = height;
    if (verif_window_struct(window) == NULL)
        return NULL;
    return window;
}
