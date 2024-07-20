/*
** EPITECH PROJECT, 2024
** my_rpg.c
** File description:
** rpg main part (like a main)
*/

#include "my_rpg.h"

/**
 * @brief Main function of the rpg
 * @param void
 * @return int
*/
int my_rpg(void)
{
    my_rpg_t *rpg = create_rpg();
    int status = 0;

    if (rpg == NULL)
        return 84;
    splash_screen(rpg);
    status = choose_loop(rpg);
    destroy_rpg(rpg);
    if (status == 84)
        return 84;
    return 0;
}
