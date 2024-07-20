/*
** EPITECH PROJECT, 2024
** handle_dialogue.c
** File description:
** handle_dialogue function
*/

#include "my_rpg.h"

void next_dialogue_line(dialogue_t *dialogue)
{
    if (dialogue->current_line < dialogue->total_lines - 1) {
        dialogue->current_line++;
        sfText_setString(dialogue->text,
                        dialogue->lines[dialogue->current_line]);
    } else {
        sfText_setString(dialogue->text, "");
    }
}

void handle_dialogue_event(dialogue_t *dialogue, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        next_dialogue_line(dialogue);
    }
}
