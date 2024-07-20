/*
** EPITECH PROJECT, 2024
** draw_hub.c
** File description:
** draw everything related to hub
*/

#include "my_rpg.h"

/**
 * @brief Function to draw the text
 * @param window window of the game
 * @param text text to draw
 * @return void
*/
void draw_text(sfRenderWindow *window, sfText *text)
{
    sfRenderWindow_drawText(window, text, NULL);
}

/**
 * @brief Function to draw a rectangle
 * @param window window of the game
 * @param rect rectangle to draw
 * @return void
*/
void draw_rectangle(sfRenderWindow *window, sfRectangleShape *rect)
{
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
}

/**
 * @brief Function to draw the hud
 * @param window window of the game
 * @param hud struct of the hud
 * @return void
*/
void draw_hud(sfRenderWindow *window, hud_t *hud)
{
    draw_text(window, hud->nom);
    draw_text(window, hud->niveau);
    draw_text(window, hud->xp_text);
    draw_rectangle(window, hud->xp_bar_bg);
    draw_rectangle(window, hud->xp_bar);
    draw_text(window, hud->message);
}
