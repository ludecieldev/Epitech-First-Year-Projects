/*
** EPITECH PROJECT, 2022
** STRUCT MY_HUNTER
** File description:
** STRUCTURES
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#ifndef MY_rpg_H
    #define MY_rpg_H
    #define UNUSED __attribute__((unused))
    #define WIDTH 1920
    #define HEIGHT 1080
    #define DARK_RED 80, 0, 0, 255
    #define SCREEN_W rpg->screen->width
    #define SCREEN_H rpg->screen->height
    #define SCREEN_WNDW rpg->screen->window
    #define SCREEN_VIEW rpg->screen->view
    #define SCREEN rpg->screen
    #define DRAWING rpg->drawing
    #define SCREEN rpg->screen
    #define SETTINGS rpg->settings
    #define RAND_COLOR rand() % 255, rand() % 255, rand() % 255, 255
    #define KEY_PRESSED event->type == sfEvtKeyPressed
    #define KEY_CODE event->key.code
    #define KEYBOARD_PRESSED sfKeyboard_isKeyPressed
    #define MOUSE_PRESSED sfMouse_isButtonPressed
    #define MENU_NB_BUTTONS 3
    #define MENU_NB_TEXTS 3
    #define INSIDE_TEXT_COLOR 144, 0, 0, 255
    #define OUTSIDE_TEXT_COLOR sfBlack
    #define TEXT_RESOLUTION settings->texts[RESOLUTION]
    #define TEXT_FULLSCREEN settings->texts[FULLSCREEN]
    #define TEXT_BACK settings->texts[BACK]
    #define TEXT_VOLUME settings->texts[VOLUME]
    #define TEXT_RESOLUTIONS settings->resolution_texts[i].text
    #define TEXT_FULLSCREENS settings->fullscreen_texts[i].text
    #define TEXT_1080p settings->resolution_texts[RES_1920_1080]
    #define TEXT_720p settings->resolution_texts[RES_1280_720]
    #define TEXT_480p settings->resolution_texts[RES_720_480]
    #define TEXT_ON settings->fullscreen_texts[0]
    #define TEXT_OFF settings->fullscreen_texts[1]
    #define TEXT_ON_VSYNC settings->vsync_texts[0]
    #define TEXT_OFF_VSYNC settings->vsync_texts[1]
    #define TEXT_FPS_60 settings->fps_texts[0]
    #define TEXT_FPS_144 settings->fps_texts[1]
    #define TEXT_FPS_240 settings->fps_texts[2]
    #define TEXT_FPS_UNLIMITED settings->fps_texts[3]
    #define FPS_TEXTS rpg->settings->fps_texts
    #define VSYNC_TEXTS rpg->settings->vsync_texts
    #define TEXT_FPS settings->texts[FPS]
    #define TEXT_VSYNC settings->texts[VSYNC]

typedef struct dialogue_s {
    sfText *text;
    sfFont *font;
    char **lines;
    int current_line;
    int total_lines;
} dialogue_t;

typedef struct text_hud_s {
    sfFont *font;
    int size;
    sfColor color;
    const char *str;
} text_hud_t;

typedef struct rect_s {
    sfColor fillColor;
    sfVector2f size;
    sfColor outlineColor;
    float outlineThickness;
} rect_t;

typedef struct hud_s {
    sfFont *font;
    sfText *nom;
    sfText *niveau;
    sfText *xp_text;
    sfRectangleShape *xp_bar;
    sfRectangleShape *xp_bar_bg;
    sfText *message;
    text_hud_t textParams;
    rect_t xpBarParams;
    rect_t xpBarBgParams;
} hud_t;

typedef struct enemy_s {
    sfClock *clock;
    sfVector2f pos;
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfFloatRect hitbox;
    sfTime mobtime;
    float mob_seconds;
    int hp;
    int damage;
} enemy_t;

typedef struct pnj_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} pnj_t;

typedef struct help_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
} help_t;

enum stats {
    HP,
    MOVE_SPEED,
    DAMAGE,
    MANA,
    LEVEL,
    XP,
    XP_NEXT_LVL
};

typedef struct player_s {
    sfVector2f pos;
    sfClock *clock;
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfFloatRect hitbox;
    int stats[7];
} player_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f position;
    sfColor color;
    int size;
    char *str;
    bool is_active;
}text_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2u size;
    sfFloatRect hitbox;
}sprite_t;

typedef struct rectangle_shape_s {
    sfRectangleShape *rect;
    sfVector2f position;
    sfVector2f size;
    sfColor color;
}rectangle_shape_t;

typedef struct circle_shape_s {
    sfCircleShape *circle;
    sfVector2f position;
    sfVector2f size;
    sfColor color;
}circle_shape_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfView *view;
    int width;
    int height;
}window_t;

typedef struct cursor_s {
    sfTexture *texture;
    sfSprite *sprite;
}cursor_t;

typedef void (*button_func_t)(void *data);

typedef struct button_s {
    bool is_active;
    text_t text;
    button_func_t func;
    rectangle_shape_t *rect;
} button_t;

typedef struct slider_s {
    rectangle_shape_t *rect;
    rectangle_shape_t *rect_;
    circle_shape_t *circle;
}slider_t;

enum text_type {
    PLAY,
    SETTINGS_,
    QUIT
};

enum button_type {
    PLAY_BUTTON,
    SETTINGS_BUTTON,
    QUIT_BUTTON
};

typedef struct menu_s {
    sprite_t background;
    sprite_t title;
    text_t texts[MENU_NB_TEXTS];
    button_func_t buttons_func[MENU_NB_BUTTONS];
    sfMusic *music;
}menu_t;

typedef struct splash_screen_s {
    sprite_t background;
    sprite_t title;
    sfClock *clock;
    text_t welcome;
    text_t to;
    float time;
    float scale;
}splash_screen_t;

enum settings_type {
    RESOLUTION,
    FULLSCREEN,
    BACK,
    VSYNC,
    VOLUME,
    FPS
};

enum slider_type {
    VOLUME_SLIDER
};

enum resolution_type {
    RES_1920_1080,
    RES_1280_720,
    RES_720_480
};

enum is_active {
    BOOL_BACK,
    BOOL_1080p,
    BOOL_720p,
    BOOL_480p,
    BOOL_ON,
    BOOL_OFF,
    BOOL_ON_VSYNC,
    BOOL_OFF_VSYNC,
    BOOL_FPS_60,
    BOOL_FPS_144,
    BOOL_FPS_240,
    BOOL_FPS_UNLIMITED
};

enum resolution_type_color {
    RES_1920_1080_TYPE,
    RES_1280_720_TYPE,
    RES_720_480_TYPE
};

typedef struct settings_s {
    text_t texts[6];
    text_t resolution_texts[3];
    text_t fullscreen_texts[2];
    text_t vsync_texts[2];
    text_t fps_texts[4];
    button_func_t buttons_func[3];
    slider_t sliders;
    sfKeyCode move_keys[4];
    sfVector2f resolution;
    sfFloatRect rect[12];
    int volume;
    int fps;
    bool fullscreen;
    bool vsync;
    int resolution_type;
    bool is_active[12];
}settings_t;

typedef struct item_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int item_id;
    int type;
    char *name;
    bool is_picked;
} item_t;

typedef struct inventory_t {
    sfSprite *sprite_inv;
    sfTexture *texture_inv;
    sfSprite *sprite_invgem;
    sfTexture *texture_invgem;
    sfSprite *sprite_invskull;
    sfTexture *texture_invskull;
    sfSprite *sprite_invboth;
    sfTexture *texture_invboth;
    sfVector2f pos;
    sfIntRect rect;
    item_t *items;
    int size;
    int max_size;
    int is_visible;
    player_t *player;
    bool is_gem_picked;
    bool is_skull_picked;
    bool is_both_picked;
    bool is_empty;
} inventory_t;

enum move_keys {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct game_s {
    player_t *player;
    enemy_t *enemy;
    help_t *help;
    pnj_t *pnj;
    sprite_t background;
    sfClock *clock;
    sfTime time;
    sfVector2f move;
    sfVector2f move_speed;
    sfVector2f move_keys[4];
    sfVector2f move_keys_speed[4];
    inventory_t *inventory;
    item_t *items;
    sfVector2f mouse_pos;
    sfView *view;
    sfImage *map;
    sprite_t hover;
}game_t;

enum loop_mode {
    MENU_LOOP,
    GAME_LOOP,
    SETTINGS_LOOP,
    QUIT_LOOP
};

typedef struct my_rpg_s {
    window_t *screen;
    sfVideoMode mode;
    cursor_t *cursor;
    menu_t *menu;
    settings_t *settings;
    game_t *game;
    int loop_value;
} my_rpg_t;

typedef struct func_for_settings_s {
    sfBool (*contains)(const sfFloatRect *, float, float);
    void (*action)(my_rpg_t *);
} func_for_settings_t;

// my_rpg.c
int my_rpg(void);
// create_rpg.c
my_rpg_t *create_rpg(void);
window_t *create_window_struct(int width, int height, char *title);
// destroy_rpg.c
void destroy_rpg(my_rpg_t *rpg);
// create_window.c
sfRenderWindow *create_window(int width, int height, char *title);
// create_view.c
sfView *create_view(void);
// screen_loop.c
int choose_loop(my_rpg_t *rpg);
int game_loop(my_rpg_t *rpg);
int menu_loop(my_rpg_t *rpg);
int settings_loop(my_rpg_t *rpg);
// create_cursor.c
cursor_t *create_cursor(void);
// window_draw.c
bool sf_drawing_part(my_rpg_t *rpg);
// set_cursor.c
bool set_cursor(my_rpg_t *rpg);
// handle_events.c
bool handle_screen_events(my_rpg_t *rpg, sfEvent *event);
// sf_set_funtcions.c
void sf_set_screen(my_rpg_t *rpg);
// verif_env.c
int verif_env_display(char **envp);
// create_menu.c
menu_t *create_menu(void);
// create_sprite.c
sprite_t create_sprite(char *path, sfVector2f pos, sfIntRect rect);
// create_texts.c
bool create_texts(my_rpg_t *rpg);
bool create_buttons_func(my_rpg_t *rpg);
text_t create_text(char *str, sfVector2f pos, int size);
// texts_events.c
void texts_events(my_rpg_t *rpg, sfVector2f world);
void is_over_text(sfText *text, sfColor c1, sfColor c2, sfVector2f wld);
void is_clicked_text(my_rpg_t *rpg, int i, sfVector2f world);
// screen_events.c
void screen_events(my_rpg_t *rpg, sfEvent *event);
// menu functions (pointer to functions)
void play_func(void *data);
void settings_func(void *data);
void quit_func(void *data);
// destroy funtions
void destroy_texts(my_rpg_t *rpg);
void destroy_menu(my_rpg_t *rpg);
void destroy_cursor(my_rpg_t *rpg);
void free_rpg(my_rpg_t *rpg);
// create_splash_screen.c
splash_screen_t *create_splash_screen(void);
// update_splash_screen.c
void update_splash_positions(splash_screen_t *splash, sfVector2f *position,
    my_rpg_t *rpg);
// splash_screen.c
bool splash_screen(my_rpg_t *rpg);
// functions_for_settings.c
void resolution_func(void *data);
void fullscreen_func(void *data);
void back_func(void *data);
// create_slider.c
slider_t *create_slider(sfVector2f pos, sfVector2f size, int value);
circle_shape_t *create_circle_t(sfVector2f pos, float radius, sfColor color);
rectangle_shape_t *create_rectangle_t(sfVector2f pos, sfVector2f size,
    sfColor color);
// create_settings.c
settings_t *create_settings(void);
// combat_system
void update_combat(player_t *player, enemy_t *enemy);
void draw_entities(sfRenderWindow *window, player_t *player, enemy_t *enemy);
// func_for_settings
void back_function(my_rpg_t *rpg);
void fhd_func(my_rpg_t *rpg);
void hd_func(my_rpg_t *rpg);
void sd_func(my_rpg_t *rpg);
void on_func(my_rpg_t *rpg);
void off_func(my_rpg_t *rpg);
void on_vsync_func(my_rpg_t *rpg);
void off_vsync_func(my_rpg_t *rpg);
void fps_60_func(my_rpg_t *rpg);
void fps_144_func(my_rpg_t *rpg);
void fps_240_func(my_rpg_t *rpg);
void fps_unlimited_func(my_rpg_t *rpg);
void sfrenderwindow_setfullscreen(sfRenderWindow *window, sfBool fullscreen,
    my_rpg_t *rpg);
// inventory
inventory_t *init_inventory(player_t *player);
void check_inventory_key(my_rpg_t *rpg, sfEvent event);
void toggle_inventory_display(inventory_t *inv);
void destroy_inventory(inventory_t *inv);
// items
item_t *create_item(char *path, char *name, int type);
void destroy_item(item_t *item);
bool save_items(item_t *items);
bool load_items(item_t *items);
void display_items(sfRenderWindow *window, item_t *items);
// player
player_t *init_player(void);
void destroy_player(player_t *gojo);
//enemy
enemy_t *init_enemy(void);
void enemy_animation(enemy_t *mob);
void destroy_enemy(enemy_t *mob);
//display_help
help_t *init_help(void);
void destroy_help(help_t *help);
void set_zone_for_help(my_rpg_t *rpg);
//pnj
pnj_t *init_pnj(void);
void destroy_pnj(pnj_t *pnj);
// game utils
void moves_keys_events(my_rpg_t *rpg);
bool game_events(my_rpg_t *rpg);
void move_right(my_rpg_t *rpg);
void move_left(my_rpg_t *rpg);
void move_down(my_rpg_t *rpg);
void move_up(my_rpg_t *rpg);
void set_cursor_game(my_rpg_t *rpg);
void game_drawing_part(my_rpg_t *rpg);
// settings utils
void settings_texts_events(my_rpg_t *rpg, sfVector2f world,
    UNUSED sfEvent event);
void is_clicked_settings(my_rpg_t *rpg, sfVector2f world);
void change_text_color(my_rpg_t *rpg, sfColor color);
bool settings_events(my_rpg_t *rpg);
// enemy
void enemy_animation(enemy_t *mob);
void move_animation(player_t *player);
#endif /* !MY_rpg_H */
