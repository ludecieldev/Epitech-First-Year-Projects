/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** initi.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

int init_var(char **av, parsing_t *pars)
{
    pars->nb_plane = 0;
    pars->nb_tower = 0;
    pars->file_array = load_file(av[1], pars);
    if (pars->file_array == NULL)
        return ERROR;
    return SUCCESS;
}

int init_window(window_t *window)
{
    window->mode.width = 1920;
    window->mode.height = 1080;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, "My_Radar",
    sfDefaultStyle, NULL);
    window->back_tx = sfTexture_createFromFile(BACKGROUND, NULL);
    window->back_sp = sfSprite_create();
    sfSprite_setTexture(window->back_sp, window->back_tx, sfTrue);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    if (!window->window || !window->back_tx || !window->back_sp)
        return ERROR;
    return SUCCESS;
}

int init_texture(texture_t *texture)
{
    texture->text_tower = sfTexture_createFromFile(TOWER_TEXTURE, NULL);
    texture->text_plane = sfTexture_createFromFile(PLANE_TEXTURE, NULL);
    texture->sprite_tower = sfSprite_create();
    texture->sprite_plane = sfSprite_create();
    sfSprite_setTexture(texture->sprite_tower,
    texture->text_tower, sfTrue);
    sfSprite_setTexture(texture->sprite_plane,
    texture->text_plane, sfTrue);
    if (!texture->text_tower || !texture->text_plane ||
    !texture->sprite_tower || !texture->sprite_plane)
        return ERROR;
    return SUCCESS;
}
