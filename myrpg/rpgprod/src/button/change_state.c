/*
** EPITECH PROJECT, 2024
** change_state.c
** File description:
** change the value of is_active
*/

#include "my_rpg.h"

/**
 * @brief Function to change the state of a button
 * @param active_or_not boolean
 * @return void
*/
void change_button_state(bool *active_or_not)
{
    if (*active_or_not == true)
        *active_or_not = false;
    else if (*active_or_not == false)
        *active_or_not = true;
}
