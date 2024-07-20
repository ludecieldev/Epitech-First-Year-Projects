/*
** EPITECH PROJECT, 2024
** My_RPG-Public
** File description:
** game_loop
*/

#include "my_rpg.h"

/**
 * @brief Start of the game loop
 * @param rpg Structure my_rpg
 * @return 0
*/
int game_loop(my_rpg_t *rpg)
{
    if (rpg == NULL || !game_events(rpg))
        return 84;
    game_drawing_part(rpg);
    return 0;
}
