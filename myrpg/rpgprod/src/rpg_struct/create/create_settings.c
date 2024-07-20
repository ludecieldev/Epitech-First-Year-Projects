/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_settings
*/

#include "my_rpg.h"

/**
 * @brief function to set all rectangles
 * @param settings structure of settings
 * @return void
*/
void set_rects(settings_t *settings)
{
    settings->rect[BOOL_BACK] = sfText_getGlobalBounds(TEXT_BACK.text);
    settings->rect[BOOL_1080p] = sfText_getGlobalBounds(TEXT_1080p.text);
    settings->rect[BOOL_720p] = sfText_getGlobalBounds(TEXT_720p.text);
    settings->rect[BOOL_480p] = sfText_getGlobalBounds(TEXT_480p.text);
    settings->rect[BOOL_ON] = sfText_getGlobalBounds(TEXT_ON.text);
    settings->rect[BOOL_OFF] = sfText_getGlobalBounds(TEXT_OFF.text);
    settings->rect[BOOL_ON_VSYNC] = sfText_getGlobalBounds(
        TEXT_ON_VSYNC.text);
    settings->rect[BOOL_OFF_VSYNC] = sfText_getGlobalBounds(
        TEXT_OFF_VSYNC.text);
    settings->rect[BOOL_FPS_60] = sfText_getGlobalBounds(TEXT_FPS_60.text);
    settings->rect[BOOL_FPS_144] = sfText_getGlobalBounds(TEXT_FPS_144.text);
    settings->rect[BOOL_FPS_240] = sfText_getGlobalBounds(TEXT_FPS_240.text);
    settings->rect[BOOL_FPS_UNLIMITED] = sfText_getGlobalBounds(
        TEXT_FPS_UNLIMITED.text);
}

/**
 * @brief function to set basic settings
 * @param settings structure of settings
 * @return bool
*/
bool setup_basic_settings(settings_t *settings)
{
    if (!settings)
        return false;
    for (int i = 0; i < 6; i++)
        settings->is_active[i] = false;
    settings->fullscreen = false;
    settings->vsync = false;
    settings->fps = 60;
    settings->resolution_type = RES_1920_1080_TYPE;
    settings->move_keys[UP] = sfKeyZ;
    settings->move_keys[DOWN] = sfKeyS;
    settings->move_keys[LEFT] = sfKeyQ;
    settings->move_keys[RIGHT] = sfKeyD;
    settings->resolution = (sfVector2f){1920, 1080};
    settings->buttons_func[RESOLUTION] = &resolution_func;
    settings->buttons_func[FULLSCREEN] = &fullscreen_func;
    settings->buttons_func[BACK] = &back_func;
    if (!settings->buttons_func[RESOLUTION] ||
        !settings->buttons_func[FULLSCREEN] || !settings->buttons_func[BACK])
        return false;
    return true;
}

/**
 * @brief function to set color to text
 * @param text structure of text
 * @return void
*/
void set_color_to_text(text_t *text)
{
    sfText_setColor(text->text, (sfColor){INSIDE_TEXT_COLOR});
    sfText_setOutlineColor(text->text, sfBlack);
    sfText_setOutlineThickness(text->text, 2);
}

/**
 * @brief function to set color to setiings text
 * @param settings structure of settings
 * @return void
*/
void set_color_settings_text(settings_t *settings)
{
    TEXT_FPS_60 = create_text("60", (sfVector2f){1600, 425}, 50);
    TEXT_FPS_144 = create_text("144", (sfVector2f){1600, 525}, 50);
    TEXT_FPS_240 = create_text("240", (sfVector2f){1600, 625}, 50);
    TEXT_FPS_UNLIMITED = create_text("Unlimited", (sfVector2f){1600, 725}, 50);
    for (int i = 0; i < 6; i++)
        set_color_to_text(&settings->texts[i]);
    for (int i = 0; i < 3; i++)
        set_color_to_text(&settings->resolution_texts[i]);
    for (int i = 0; i < 2; i++)
        set_color_to_text(&settings->fullscreen_texts[i]);
    for (int i = 0; i < 2; i++)
        set_color_to_text(&settings->vsync_texts[i]);
    for (int i = 0; i < 4; i++)
        set_color_to_text(&settings->fps_texts[i]);
}

/**
 * @brief function to create settings
 * @param void
 * @return settings strutc
*/
settings_t *create_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    if (settings == NULL || setup_basic_settings(settings) == false)
        return NULL;
    TEXT_RESOLUTION = create_text("Resolution", (sfVector2f){350, 300}, 70);
    TEXT_FULLSCREEN = create_text("Fullscreen", (sfVector2f){700, 300}, 70);
    TEXT_BACK = create_text("Back", (sfVector2f){80, 40}, 70);
    TEXT_VSYNC = create_text("Vsync", (sfVector2f){1000, 300}, 70);
    TEXT_VOLUME = create_text("Volume", (sfVector2f){1300, 300}, 70);
    TEXT_FPS = create_text("FPS", (sfVector2f){1600, 300}, 50);
    TEXT_1080p = create_text("1920x1080", (sfVector2f){350, 425}, 50);
    TEXT_720p = create_text("1280x720", (sfVector2f){350, 525}, 50);
    TEXT_480p = create_text("720x480", (sfVector2f){350, 625}, 50);
    TEXT_ON = create_text("On", (sfVector2f){700, 425}, 50);
    TEXT_OFF = create_text("Off", (sfVector2f){700, 525}, 50);
    TEXT_ON_VSYNC = create_text("On", (sfVector2f){1000, 425}, 50);
    TEXT_OFF_VSYNC = create_text("Off", (sfVector2f){1000, 525}, 50);
    set_color_settings_text(settings);
    set_rects(settings);
    return settings;
}
