/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** splash_screen
*/

#include "my_rpg.h"

/**
 * @brief Function to initialize the splash screen
 * @param splash struct of the splash screen
 * @param rpg struct of the game
 * @return void
*/
static void init_splash_screen(splash_screen_t *splash, my_rpg_t *rpg)
{
    sfSprite_setPosition(splash->title.sprite, splash->title.position);
    sfSprite_setPosition(rpg->menu->background.sprite, (sfVector2f){-1920, 0});
    sfRenderWindow_setMouseCursorVisible(SCREEN_WNDW, sfFalse);
}

/**
 * @brief Function to handle the splash screen events
 * @param window struct of the window
 * @param event struct of the event
 * @return void
*/
static void handle_splash_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event))
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
}

/**
 * @brief Function to update the title position
 * @param splash struct of the splash screen
 * @return void
*/
static void update_title_end_position(splash_screen_t *splash)
{
    splash->title.position.y -= 20;
    splash->title.position.x -= 1;
    if (splash->title.position.x < (WIDTH / 2 - 500))
        splash->title.position.x = WIDTH / 2 - 500;
    if (splash->title.position.y < 100)
        splash->title.position.y = 100;
    sfSprite_setPosition(splash->title.sprite, splash->title.position);
}

/**
 * @brief Function to drop the splash screen
 * @param splash struct of the splash screen
 * @param window struct of the window
 * @param rpg struct of the game
 * @return void
*/
static void draw_splash_screen(sfRenderWindow *window, my_rpg_t *rpg,
    splash_screen_t *splash)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, rpg->menu->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, splash->title.sprite, NULL);
    if (splash->time < 3.5f) {
        sfRenderWindow_drawText(window, splash->welcome.text, NULL);
        sfRenderWindow_drawText(window, splash->to.text, NULL);
    } else {
        update_title_end_position(splash);
    }
    sfRenderWindow_display(window);
}

/**
 * @brief Function to destroy the splash screen
 * @param splash struct of the splash screen
 * @return splash_screen_t struct of the splash screen
*/
static void destroy_splash_screen(splash_screen_t *splash)
{
    sfClock_destroy(splash->clock);
    sfSprite_destroy(splash->title.sprite);
    sfTexture_destroy(splash->title.texture);
    sfSprite_destroy(splash->background.sprite);
    sfTexture_destroy(splash->background.texture);
    sfFont_destroy(splash->welcome.font);
    sfFont_destroy(splash->to.font);
    sfText_destroy(splash->welcome.text);
    sfText_destroy(splash->to.text);
    free(splash);
}

/**
 * @brief Function to display the splash screen
 * @param rpg struct of the game
 * @return bool
*/
bool splash_screen(my_rpg_t *rpg)
{
    splash_screen_t *splash = create_splash_screen();
    sfVector2f position = {0, 0};
    sfEvent event;

    if (!splash || !rpg)
        return false;
    init_splash_screen(splash, rpg);
    while (splash->time < 5.0f) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            destroy_splash_screen(splash);
            return true;
        }
        handle_splash_events(SCREEN_WNDW, &event);
        update_splash_positions(splash, &position, rpg);
        draw_splash_screen(SCREEN_WNDW, rpg, splash);
        sfSleep(sfMilliseconds(32));
        splash->time = sfTime_asSeconds(sfClock_getElapsedTime(splash->clock));
    }
    destroy_splash_screen(splash);
    return true;
}
