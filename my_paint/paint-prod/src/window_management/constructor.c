/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** constructor
*/

#include "window.h"

window_t *create_window(char *name)
{
    window_t *window = malloc(sizeof(window_t));

    window->name = name;
    window->event = (sfEvent){0};
    window->view = sfView_create();
    window->__init_window__ = &init_window;
    window->__destroy_window__ = &destroy_window;
    window->__display_window__ = &display_window;
    window->__init_window__(window);
    window->__handle_events__ = &handle_events;
    return (window);
}
