/*
** EPITECH PROJECT, 2024
** create_cursor.c
** File description:
** create cursor struct
*/

#include "my_rpg.h"

/**
 * @brief Function to create a cursor
 * @param void
 * @return cursor_t*
*/
cursor_t *create_cursor(void)
{
    cursor_t *cursor = calloc(1, sizeof(cursor_t) + 1);

    if (cursor == NULL)
        return NULL;
    cursor->texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    cursor->sprite = sfSprite_create();
    if (cursor->texture == NULL) {
        sfSprite_destroy(cursor->sprite);
        free(cursor);
        return NULL;
    } else if (cursor->sprite == NULL) {
        sfTexture_destroy(cursor->texture);
        free(cursor);
        return NULL;
    }
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setScale(cursor->sprite, (sfVector2f){0.12, 0.12});
    return cursor;
}
