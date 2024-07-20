/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** main
*/

#include "window.h"

int main(void)
{
    window_t *window = create_window("My_Paint");

    while (sfRenderWindow_isOpen(window->window)) {
        window->__handle_events__(window);
        window->__display_window__(window);
    }
    window->__destroy_window__(window);
    free(window);
    return 0;
}
