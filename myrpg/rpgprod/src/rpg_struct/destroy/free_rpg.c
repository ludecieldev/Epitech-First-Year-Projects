/*
** EPITECH PROJECT, 2024
** destroy_rpg.c
** File description:
** destroy struct rpg
*/

#include "my_rpg.h"

/**
 * @brief Function to free the rpg
 * @param rpg struct of the game
 * @return void
*/
void free_rpg(my_rpg_t *rpg)
{
    free(rpg->cursor);
    free(rpg->screen);
    free(rpg->menu);
    free(rpg);
}
