/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** funcs_back
*/

#include "my_rpg.h"

/**
 * @brief Function to return menu loop
 * @param rpg struct of rpg
 * @return void
*/
void back_function(my_rpg_t *rpg)
{
    rpg->loop_value = MENU_LOOP;
}
