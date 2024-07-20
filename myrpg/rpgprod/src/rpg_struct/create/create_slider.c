/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_slider
*/

#include "my_rpg.h"

/**
 * @brief function to create rectangle
 * @param pos size and color of rpg
 * @return rect
*/
rectangle_shape_t *create_rectangle_t(sfVector2f pos, sfVector2f size,
    sfColor color)
{
    rectangle_shape_t *rect = malloc(sizeof(rectangle_shape_t) + 1);

    if (rect == NULL)
        return NULL;
    rect->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect->rect, pos);
    sfRectangleShape_setSize(rect->rect, size);
    sfRectangleShape_setFillColor(rect->rect, color);
    return rect;
}

/**
 * @brief function to create all cercles
 * @param postion radius and color of rpg
 * @return circle
*/
circle_shape_t *create_circle_t(sfVector2f pos, float radius, sfColor color)
{
    circle_shape_t *circle = malloc(sizeof(circle_shape_t) + 1);

    if (circle == NULL)
        return NULL;
    circle->circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle->circle, pos);
    sfCircleShape_setRadius(circle->circle, radius);
    sfCircleShape_setFillColor(circle->circle, color);
    return circle;
}

/**
 * @brief function to create all sliders
 * @param postion size & value
 * @return slider
*/
slider_t *create_slider(sfVector2f pos, sfVector2f size, int value)
{
    slider_t *slider = malloc(sizeof(slider_t) + 1);

    if (slider == NULL)
        return NULL;
    slider->circle = create_circle_t((sfVector2f){pos.x + value, pos.y},
    10, sfRed);
    slider->rect = create_rectangle_t(pos, size, sfWhite);
    slider->rect_ = create_rectangle_t((sfVector2f){pos.x + value, pos.y},
    (sfVector2f){10, 10}, sfRed);
    return slider;
}
