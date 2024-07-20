/*
** EPITECH PROJECT, 2024
** init_text.c
** File description:
** init text
*/


#include "my_rpg.h"

/**
 * @brief Function to init a text
 * @param text text to init
 * @param params struct of the text
 * @return void
*/
void init_text(sfText **text, text_hud_t *params)
{
    *text = sfText_create();
    sfText_setFont(*text, params->font);
    sfText_setCharacterSize(*text, params->size);
    sfText_setFillColor(*text, params->color);
    if (params->str != NULL) {
        sfText_setString(*text, params->str);
    }
}
