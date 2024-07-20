/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** mouse_scope.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void replace_mouse_scope(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x -65, mouse_pos.y - 55};
    sfSprite *mouse_scope = sfSprite_create();
    sfTexture *mouse_scope_texture = sfTexture_createFromFile(
        "assets/mouse_scope.png", NULL);

    sfSprite_setScale(mouse_scope, (sfVector2f){0.3, 0.3});
    sfSprite_setTexture(mouse_scope, mouse_scope_texture, sfTrue);
    sfSprite_setPosition(mouse_scope, mouse_pos_f);
    sfRenderWindow_drawSprite(window, mouse_scope, NULL);
}
