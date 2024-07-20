/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_menu
*/

#include "my_rpg.h"

/**
 * @brief Function to create the menu
 * @param void
 * @return menu_t*
*/
menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (menu == NULL)
        return NULL;
    menu->background = create_sprite("assets/menu/background.jpg",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    menu->title = create_sprite("assets/menu/title.png",
    (sfVector2f){WIDTH / 2 - 500, 100}, (sfIntRect){0, 0, 1024, 280});
    menu->music = NULL;
    if (menu->background.sprite == NULL || menu->title.sprite == NULL)
        return NULL;
    return menu;
}
