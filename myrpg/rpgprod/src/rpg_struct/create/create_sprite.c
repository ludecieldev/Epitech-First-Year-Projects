/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_sprite
*/

#include "my_rpg.h"

/**
 * @brief Function to create a sprite
 * @param path path of the sprite
 * @param pos position of the sprite
 * @param rect rect of the sprite
 * @return sprite_t
*/
sprite_t create_sprite(char *path, sfVector2f pos, sfIntRect rect)
{
    sprite_t sprite = {0};

    sprite.texture = sfTexture_createFromFile(path, NULL);
    if (sprite.texture == NULL)
        return (sprite_t){0};
    sprite.sprite = sfSprite_create();
    sprite.hitbox = sfSprite_getGlobalBounds(sprite.sprite);
    sprite.size = sfTexture_getSize(sprite.texture);
    sprite.position = pos;
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    sfSprite_setPosition(sprite.sprite, pos);
    sfSprite_setTextureRect(sprite.sprite, rect);
    return sprite;
}
