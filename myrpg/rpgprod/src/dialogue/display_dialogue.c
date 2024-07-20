/*
** EPITECH PROJECT, 2024
** display_dialogue.c
** File description:
** display_dialogue function
*/

#include "my_rpg.h"

void display_dialogue(dialogue_t *dialogue, sfRenderWindow *window)
{
    if (dialogue && dialogue->text) {
        sfRenderWindow_drawText(window, dialogue->text, NULL);
    }
}
