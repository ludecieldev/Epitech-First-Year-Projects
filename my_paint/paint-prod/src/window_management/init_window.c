/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** init_window
*/

#include "window.h"

void init_window(window_t *this)
{
    sfVideoMode mode = {1920, 1080, 32};

    this->window = sfRenderWindow_create(mode, this->name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(this->window, 60);
}
