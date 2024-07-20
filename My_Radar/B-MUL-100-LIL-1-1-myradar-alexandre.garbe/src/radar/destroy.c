/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** destroy.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

void desall(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    sfSprite_destroy(window->back_sp);
    sfTexture_destroy(window->back_tx);
}
