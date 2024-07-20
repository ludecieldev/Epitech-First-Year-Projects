/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** create_splash_screen
*/

#include "my_rpg.h"

/**
 * @brief Function to create a text
 * @param str string of the text
 * @param pos position of the text
 * @param size size of the text
 * @return text_t struct of the text
*/
text_t create_text_t(char *str, sfVector2f pos, int size)
{
    text_t text;

    text.font = sfFont_createFromFile("assets/font/jjk.ttf");
    text.text = sfText_create();
    if (!text.font || !text.text)
        return (text_t){0};
    sfText_setFont(text.text, text.font);
    sfText_setString(text.text, str);
    sfText_setCharacterSize(text.text, size);
    sfText_setPosition(text.text, pos);
    return text;
}

/**
 * @brief Function to create the text of the splash screen
 * @param splash struct of the splash screen
 * @return void
*/
void create_text_splash(splash_screen_t *splash)
{
    splash->welcome = create_text_t("WELCOME", (sfVector2f){600, 800}, 100);
    splash->to = create_text_t("TO", (sfVector2f){700, 900}, 100);
    if (!splash->welcome.font || !splash->welcome.text
        || !splash->to.font || !splash->to.text)
        return;
    sfText_setColor(splash->welcome.text, (sfColor){INSIDE_TEXT_COLOR});
    sfText_setColor(splash->to.text, (sfColor){INSIDE_TEXT_COLOR});
    sfText_setOutlineColor(splash->welcome.text, sfBlack);
    sfText_setOutlineColor(splash->to.text, sfBlack);
    sfText_setOutlineThickness(splash->welcome.text, 4);
    sfText_setOutlineThickness(splash->to.text, 4);
    sfText_setCharacterSize(splash->welcome.text, 130);
    sfText_setCharacterSize(splash->to.text, 130);
    splash->welcome.position = (sfVector2f){-550, 200};
    splash->to.position = (sfVector2f){1940, 200};
    sfText_setPosition(splash->welcome.text, splash->welcome.position);
    sfText_setPosition(splash->to.text, splash->to.position);
}

/**
 * @brief Function to create the splash screen background
 * @param splash struct of the splash screen
 * @return void
*/
static void create_splash_background(splash_screen_t *splash)
{
    splash->background = create_sprite("assets/menu/background.jpg",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
}

/**
 * @brief Function to create the splash screen title
 * @param splash struct of the splash screen
 * @return void
*/
static void create_splash_title(splash_screen_t *splash)
{
    splash->title = create_sprite("assets/menu/title.png",
        (sfVector2f){480, 1000}, (sfIntRect){0, 0, 960, 540});
}

/**
 * @brief Function to set the textures of the splash screen
 * @param splash struct of the splash screen
 * @return void
*/
static void set_splash_textures(splash_screen_t *splash)
{
    sfSprite_setTexture(splash->background.sprite, splash->background.texture,
        sfTrue);
    sfSprite_setTexture(splash->title.sprite, splash->title.texture, sfTrue);
}

/**
 * @brief Function to create the splash screen
 * @param void
 * @return splash_screen_t* struct of the splash screen
*/
splash_screen_t *create_splash_screen(void)
{
    splash_screen_t *splash = malloc(sizeof(splash_screen_t));

    if (!splash)
        return NULL;
    create_splash_background(splash);
    create_splash_title(splash);
    splash->clock = sfClock_create();
    splash->time = 0.f;
    splash->scale = 0.f;
    if (!splash->background.texture || !splash->title.texture
        || !splash->clock || !splash->background.sprite
        || !splash->title.sprite)
        return NULL;
    set_splash_textures(splash);
    create_text_splash(splash);
    return splash;
}
