/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of my_rpg project
*/

#include "my_rpg.h"

/**
 * @brief main function of the project
 * @param argc number of arguments
 * @param argv arguments
 * @param envp environment
 * @return int
*/
int main(UNUSED int argc, UNUSED char **argv, char **envp)
{
    if (envp[0] == NULL) {
        dprintf(2, "Hey, you need to have an environment ;)\n");
        return 84;
    }
    if (verif_env_display(envp) == 84)
        return 84;
    return my_rpg();
}
