/*
** EPITECH PROJECT, 2024
** verif_env.c
** File description:
** verif if we are in tty (no display in env + no env (-i))
*/

#include "my_rpg.h"

/**
 * @brief Function to verify if we are in tty
 * @param envp env
 * @return int
*/
int verif_env_display(char **envp)
{
    for (int i = 0; envp[i] != NULL; i++)
        if (strncmp(envp[i], "DISPLAY", 7) == 0)
            return 0;
    write(2, "DISPLAY not found\n", 18);
    write(2, "I see you trying to make me crash\n", 34);
    return 84;
}
