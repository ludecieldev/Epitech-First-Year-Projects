/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** destroy_window
*/

#include "window.h"

void destroy_window(window_t *this)
{
    sfRenderWindow_destroy(this->window);
}
