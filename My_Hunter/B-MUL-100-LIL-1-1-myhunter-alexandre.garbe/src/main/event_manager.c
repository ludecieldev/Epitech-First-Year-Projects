/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** event_manager.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void mouse_getter(window_t *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            my_putstr("Mouse X = ");
            my_put_nbr(event.mouseButton.x);
            my_putstr(" Y = ");
            my_put_nbr(event.mouseButton.y);
            my_putchar('\n');
        }
    }
}

void check_player_position(window_t *window, sfEvent event, mob_t *mob)
{
    my_putstr("Sprite X = ");
    my_put_nbr(mob->x);
    my_putstr(" Y = ");
    my_put_nbr(mob->y);
    my_putchar('\n');
    if (event.mouseButton.x >= mob->x && event.mouseButton.x
    <= mob->x + SPRITE_WIDTH
        && event.mouseButton.y >= mob->y && event.mouseButton.y
        <= mob->y + SPRITE_HEIGHT) {
        mob->x = -200;
        mob->nb_hit += 1;
        sfSprite_setPosition(mob->sprite, (sfVector2f){mob->x, mob->y});
    }
}

void event_manager(window_t *window, sfEvent event, mob_t *mob)
{
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_getter(window, event);
            check_player_position(window, event, mob);
        }
    }
}
