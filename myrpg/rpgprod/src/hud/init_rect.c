/*
** EPITECH PROJECT, 2024
** init_rect.c
** File description:
** init rectangle
*/

#include "my_rpg.h"

/**
 * @brief Function to init a rectangle
 * @param rect rectangle to init
 * @param params parameters of the rectangle
 * @return void
*/
void init_rectangle(sfRectangleShape **rect, rect_t *params)
{
    *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(*rect, params->fillColor);
    sfRectangleShape_setSize(*rect, params->size);
    if (params->outlineColor.a != 0) {
        sfRectangleShape_setOutlineColor(*rect, params->outlineColor);
        sfRectangleShape_setOutlineThickness(*rect, params->outlineThickness);
    }
}
