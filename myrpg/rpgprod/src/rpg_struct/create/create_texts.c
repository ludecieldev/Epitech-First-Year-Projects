/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_texts
*/

#include "my_rpg.h"

/**
 * @brief Function to create text with color
 * @param rpg struct of the game
 * @param c1 color of the text
 * @param c2 color of the outline
 * @return void
*/
void create_texts_color(my_rpg_t *rpg, sfColor c1, sfColor c2)
{
    unsigned int size = 0;
    float thickness = 0.f;

    for (int i = 0; i < MENU_NB_TEXTS; i++) {
        size = sfText_getCharacterSize(rpg->menu->texts[i].text);
        thickness = size * 0.08;
        sfText_setColor(rpg->menu->texts[i].text, c1);
        sfText_setOutlineColor(rpg->menu->texts[i].text, c2);
        sfText_setOutlineThickness(rpg->menu->texts[i].text, thickness);
    }
}

/**
 * @brief Function to create a text
 * @param str string of the text
 * @param pos position of the text
 * @param size size of the text
 * @return text_t
*/
text_t create_text(char *str, sfVector2f pos, int size)
{
    text_t text = {0};
    sfFloatRect text_rect = {0};

    text.text = sfText_create();
    text.font = sfFont_createFromFile("assets/font/jjk.ttf");
    text.is_active = false;
    if (text.text == NULL || text.font == NULL)
        return (text_t){0};
    sfText_setString(text.text, str);
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, size);
    text_rect = sfText_getGlobalBounds(text.text);
    sfText_setPosition(text.text, (sfVector2f){pos.x - text_rect.width / 2,
        pos.y - text_rect.height / 2});
    return text;
}

/**
 * @brief Function to create the texts
 * @param rpg struct of the game
 * @return bool
*/
bool create_texts(my_rpg_t *rpg)
{
    rpg->menu->texts[PLAY] = create_text("PLAY", (sfVector2f){SCREEN_W / 2,
        SCREEN_H / 2.4}, 70);
    rpg->menu->texts[SETTINGS_] = create_text("SETTINGS",
        (sfVector2f){SCREEN_W / 2, SCREEN_H / 2.4 + 175}, 70);
    rpg->menu->texts[QUIT] = create_text("QUIT", (sfVector2f){SCREEN_W / 2,
        SCREEN_H / 2.4 + 350}, 70);
    if (rpg->menu->texts[PLAY].text == NULL
        || rpg->menu->texts[SETTINGS_].text == NULL
        || rpg->menu->texts[QUIT].text == NULL)
        return false;
    create_texts_color(rpg, (sfColor){INSIDE_TEXT_COLOR}, OUTSIDE_TEXT_COLOR);
    return true;
}
