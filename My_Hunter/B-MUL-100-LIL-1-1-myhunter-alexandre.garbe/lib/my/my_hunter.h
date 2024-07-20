/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
** File description:
** my_hunter.h
** Author:
** ludeciel
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #define SPRITE_WIDTH 100
    #define SPRITE_HEIGHT 100
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <pwd.h>
    #include <grp.h>

typedef struct textures {
    sfTexture *game_texture;
    sfSprite *game_sprite;
    sfTexture *mouse_scope_texture;
    sfSprite *mouse_scope_sprite;
} textures_t;

typedef struct window {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    char *title;
    sfVector2u size;
    sfText *score;
    sfFont *font;
} window_t;

typedef struct mob {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    float x;
    float y;
    sfTexture *sprite_texture;
    sfSprite *sprite;
    int nb_hit;
}mob_t;

typedef struct music {
    sfMusic *music;
}music_t;

int mini_printf(char const *format, ...);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_itoa(int nb);
int format_integer(int i, char const *format, va_list list, int count);
int format_string(int i, char const *format, va_list list , int count);
int format_char(int i, char const *format, va_list list, int count);
int format_modulo(int i, char const *format, va_list list, int count);
int render_window(void);
void init_windows(window_t *window);
void init_textures(textures_t *textures);
int error_texture(textures_t *textures, mob_t *mob, music_t *music);
void event_manager(window_t *window, sfEvent event, mob_t *mob);
void init_mob(mob_t *mob);
void mob_animation_classic(mob_t *mob);
void init_music(music_t *music);
void random_animation(mob_t *mob);
void replace_mouse_scope(sfRenderWindow *window, sfEvent event);
void score_management(window_t *window, mob_t *mob);

#endif /* !MY_HUNTER_H_ */
