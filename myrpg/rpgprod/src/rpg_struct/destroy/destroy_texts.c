/*
** EPITECH PROJECT, 2024
** destroy_rpg.c
** File description:
** destroy struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the texts
 * @param rpg struct of the game
 * @return void
*/
void destroy_texts(my_rpg_t *rpg)
{
    for (int i = 0; i < MENU_NB_TEXTS; i++) {
        sfText_destroy(rpg->menu->texts[i].text);
        sfFont_destroy(rpg->menu->texts[i].font);
    }
}
