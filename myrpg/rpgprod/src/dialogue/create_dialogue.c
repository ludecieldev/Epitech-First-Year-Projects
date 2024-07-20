/*
** EPITECH PROJECT, 2024
** create_dialogue.c
** File description:
** create function
*/

#include "my_rpg.h"

sfText *create_text(sfVector2f position, unsigned int size, sfColor color)
{
    const char *font_path = "assets/fonts/jjk.ttf";
    sfFont *font = sfFont_createFromFile(font_path);
    sfText *text = sfText_create();

    if (!font)
        return NULL;
    if (!text) {
        sfFont_destroy(font);
        return NULL;
    }
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setPosition(text, position);
    return text;
}

dialogue_t *create_dialogue(char **lines, int total_lines, sfVector2f position)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));

    if (!dialogue)
        return NULL;
    dialogue->text = create_text(position, 24, sfWhite);
    if (!dialogue->text) {
        free(dialogue);
        return NULL;
    }
    dialogue->font = (sfFont *)sfText_getFont(dialogue->text);
    dialogue->lines = lines;
    dialogue->total_lines = total_lines;
    dialogue->current_line = 0;
    sfText_setString(dialogue->text, dialogue->lines[dialogue->current_line]);
    return dialogue;
}
