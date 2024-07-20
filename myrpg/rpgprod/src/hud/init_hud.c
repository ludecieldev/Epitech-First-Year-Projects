/*
** EPITECH PROJECT, 2024
** init_hud.c
** File description:
** init all about hud
*/

#include "my_rpg.h"

/**
 * @brief Function to init the hud colors
 * @param hud struct of the hud
 * @return void
*/
void init_hud_texts(hud_t *hud)
{
    hud->textParams.font = hud->font;
    hud->textParams.size = 24;
    hud->textParams.color = sfWhite;
    hud->textParams.str = "Gojo";
    init_text(&hud->nom, &hud->textParams);
    hud->textParams.str = NULL;
    init_text(&hud->niveau, &hud->textParams);
    init_text(&hud->xp_text, &hud->textParams);
    hud->textParams.color = sfRed;
    init_text(&hud->message, &hud->textParams);
    sfText_setPosition(hud->message, (sfVector2f){10, 550});
    sfText_setPosition(hud->nom, (sfVector2f){550, 10});
    sfText_setPosition(hud->niveau, (sfVector2f){550, 40});
    sfText_setPosition(hud->xp_text, (sfVector2f){550, 90});
}

/**
 * @brief Function to init the hud shapes
 * @param hud struct of the hud
 * @return void
*/
void init_hud_rectangles(hud_t *hud)
{
    hud->xpBarParams.fillColor = sfGreen;
    hud->xpBarParams.size = (sfVector2f){200, 20};
    hud->xpBarParams.outlineColor = (sfColor){0, 0, 0, 0};
    hud->xpBarParams.outlineThickness = 0;
    init_rectangle(&hud->xp_bar, &hud->xpBarParams);
    hud->xpBarBgParams.fillColor = sfBlack;
    hud->xpBarBgParams.size = (sfVector2f){200, 20};
    hud->xpBarBgParams.outlineColor = sfWhite;
    hud->xpBarBgParams.outlineThickness = 2;
    init_rectangle(&hud->xp_bar_bg, &hud->xpBarBgParams);
    sfRectangleShape_setPosition(hud->xp_bar_bg, (sfVector2f){550, 70});
    sfRectangleShape_setPosition(hud->xp_bar, (sfVector2f){550, 70});
}

/**
 * @brief Function to init the hud
 * @param hud struct of the hud
 * @return void
*/
void init_hud(hud_t *hud)
{
    hud->font = sfFont_createFromFile("assets/fonts/jjk.ttf");
    init_hud_texts(hud);
    init_hud_rectangles(hud);
}
