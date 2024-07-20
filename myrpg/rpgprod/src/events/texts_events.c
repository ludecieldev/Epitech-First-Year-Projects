/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** text_events
*/

#include "my_rpg.h"

/**
 * @brief Function to check if the mouse is over a text
 * @param text text to check
 * @param c1 color 1
 * @param c2 color 2
 * @param wld world position
 * @return void
*/
void is_over_text(sfText *text, sfColor c1, sfColor c2, sfVector2f wld)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&rect, wld.x, wld.y)) {
        sfText_setColor(text, c1);
        sfText_setOutlineColor(text, c2);
    } else {
        sfText_setColor(text, (sfColor){INSIDE_TEXT_COLOR});
        sfText_setOutlineColor(text, OUTSIDE_TEXT_COLOR);
    }
}

/**
 * @brief Function to check if a text is clicked
 * @param rpg struct of the game
 * @param i index of the text
 * @param world world position
 * @return void
*/
void is_clicked_text(my_rpg_t *rpg, int i, sfVector2f world)
{
    sfFloatRect rect = sfText_getGlobalBounds(rpg->menu->texts[i].text);

    if (!rect.width || !rect.height || !rpg->menu->texts[i].text)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&rect, world.x, world.y))
            rpg->menu->buttons_func[i](rpg);
    }
}

/**
 * @brief Function to handle the texts events
 * @param rpg struct of the game
 * @param world world position
 * @return void
*/
void texts_events(my_rpg_t *rpg, sfVector2f world)
{
    for (int i = 0; i < MENU_NB_TEXTS; i++) {
        is_over_text(rpg->menu->texts[i].text, (sfColor){DARK_RED},
            sfBlack, world);
        is_clicked_text(rpg, i, world);
    }
}
