/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** display_window
*/

#include "window.h"

void display_window(window_t *this)
{
    sfRenderWindow_display(this->window);
}
