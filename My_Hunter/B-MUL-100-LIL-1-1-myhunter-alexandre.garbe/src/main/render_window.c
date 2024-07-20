/*
** EPITECH PROJECT, 2023
** MYHUNTER
** File description:
** render_window.c
** Author:
** ludeciel
*/

#include "../../lib/my/my_hunter.h"

void desall(window_t *window, textures_t *textures, mob_t *mob, music_t *music)
{
    sfRenderWindow_destroy(window->window);
    sfTexture_destroy(textures->game_texture);
    sfSprite_destroy(textures->game_sprite);
    sfTexture_destroy(mob->sprite_texture);
    sfSprite_destroy(mob->sprite);
    sfMusic_destroy(music->music);
    sfClock_destroy(mob->clock);
    sfFont_destroy(window->font);
    sfText_destroy(window->score);
}

void while_short(window_t *window, textures_t *textures, mob_t *mob)
{
    event_manager(window, window->event, mob);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, textures->game_sprite, NULL);
    sfRenderWindow_drawSprite(window->window, mob->sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    mob_animation_classic(mob);
    replace_mouse_scope(window->window, window->event);
    score_management(window, mob);
    sfRenderWindow_display(window->window);
}

int render_window(void)
{
    window_t window;
    textures_t textures;
    mob_t mob;
    music_t music;

    init_windows(&window);
    init_textures(&textures);
    init_mob(&mob);
    init_music(&music);
    window.window = sfRenderWindow_create(window.mode, window.title,
    sfResize | sfClose, NULL);
    if (error_texture(&textures, &mob, &music) == 84)
        return (84);
    sfRenderWindow_setFramerateLimit(window.window, 144);
    while (sfRenderWindow_isOpen(window.window))
        while_short(&window, &textures, &mob);
    desall(&window, &textures, &mob, &music);
    return (0);
}
