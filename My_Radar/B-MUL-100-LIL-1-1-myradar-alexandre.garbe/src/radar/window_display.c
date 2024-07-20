/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** window_display.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

void window_event_management(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
}

void display_tower(tower_t *tower, window_t *window)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, tower->radius);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setPosition(circle,
    (sfVector2f){tower->x, tower->y});
    sfRenderWindow_drawCircleShape(window->window, circle, NULL);
    sfCircleShape_destroy(circle);
}
int window_display(global_t *global, texture_t *texture, window_t *window, char **array)
{
    if (init_window(window) == ERROR ||
    init_texture(texture) == ERROR)
        return ERROR;
    while (sfRenderWindow_isOpen(window->window)) {
        window_event_management(window);
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window,
        window->back_sp, NULL);
        array_travel(array, global);
        display_tower(global->tower, window);
        sfRenderWindow_display(window->window);
    }
    desall(window);
    return SUCCESS;
}
