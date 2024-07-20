/*
** EPITECH PROJECT, 2024
** destroy_hud.c
** File description:
** destroy everything created with hud
*/

#include "my_rpg.h"

/**
 * @brief Function to destroy the hud
 * @param hud struct of the hud
 * @return void
*/
void destroy_hud(hud_t *hud)
{
    if (hud->nom)
        sfText_destroy(hud->nom);
    if (hud->niveau)
        sfText_destroy(hud->niveau);
    if (hud->xp_text)
        sfText_destroy(hud->xp_text);
    if (hud->message)
        sfText_destroy(hud->message);
    if (hud->xp_bar)
        sfRectangleShape_destroy(hud->xp_bar);
    if (hud->xp_bar_bg)
        sfRectangleShape_destroy(hud->xp_bar_bg);
    if (hud->font)
    sfFont_destroy(hud->font);
}
