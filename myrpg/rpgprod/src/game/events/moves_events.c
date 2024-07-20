/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** moves_events
*/

#include "my_rpg.h"

/**
 * @brief Function to set the diagonal movement of player
 * @param rpg struct of the my_rpg
 * @return void
*/
void combo_moves_keys_events(my_rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_up(rpg);
        move_left(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && sfKeyboard_isKeyPressed(sfKeyD)) {
        move_up(rpg);
        move_right(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_down(rpg);
        move_left(rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        move_down(rpg);
        move_right(rpg);
    }
}

/**
 * @brief Function to handle key events for the movement of player
 * @param rpg struct of the my_rpg
 * @return void
*/
void moves_keys_events(my_rpg_t *rpg)
{
    combo_moves_keys_events(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->loop_value = MENU_LOOP;
    if (sfKeyboard_isKeyPressed(rpg->settings->move_keys[UP]))
        move_up(rpg);
    if (sfKeyboard_isKeyPressed(rpg->settings->move_keys[DOWN]))
        move_down(rpg);
    if (sfKeyboard_isKeyPressed(rpg->settings->move_keys[LEFT]))
        move_left(rpg);
    if (sfKeyboard_isKeyPressed(rpg->settings->move_keys[RIGHT]))
        move_right(rpg);
}
