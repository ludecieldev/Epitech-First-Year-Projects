/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** update_splash_screen
*/

#include "my_rpg.h"

/**
 * @brief Function to update the welcome position
 * @param splash struct of the splash screen
 * @return void
 */
static void update_welcome_position(splash_screen_t *splash)
{
    if (splash->time > 1.0f && splash->time < 1.5f
        && splash->title.position.y > 800) {
        splash->welcome.position.x += 70.5;
        sfText_setPosition(splash->welcome.text, splash->welcome.position);
    }
}

/**
 * @brief Function to update the to position
 * @param splash struct of the splash screen
 * @return void
 */
static void update_to_position(splash_screen_t *splash)
{
    if (splash->time > 1.5f && splash->time < 2.0f) {
        splash->to.position.x -= 50;
        sfText_setPosition(splash->to.text, splash->to.position);
    }
}

/**
 * @brief Function to update the title position
 * @param splash struct of the splash screen
 * @return void
 */
static void update_title_position(splash_screen_t *splash)
{
    if (splash->time > 2.0f && splash->time < 2.5f
        && splash->title.position.y > 500) {
        splash->title.position.y -= 30;
        sfSprite_setPosition(splash->title.sprite, splash->title.position);
    }
}

/**
 * @brief Function to update the splash screen positions
 * @param splash struct of the splash screen
 * @param position position of the background
 * @param rpg struct of the game
 * @return void
 */
void update_splash_positions(splash_screen_t *splash, sfVector2f *position,
    my_rpg_t *rpg)
{
    if (splash->time < 1.0f) {
        position->x -= 100;
        if (position->x < 0)
            position->x = 0;
        sfSprite_setPosition(rpg->menu->background.sprite, *position);
    }
    update_welcome_position(splash);
    update_to_position(splash);
    update_title_position(splash);
}
