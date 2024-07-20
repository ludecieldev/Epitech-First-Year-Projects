/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

int main(int ac, char **av)
{
    parsing_t *pars = malloc(sizeof(parsing_t));
    texture_t *texture = malloc(sizeof(texture_t));
    window_t *window = malloc(sizeof(window_t));
    global_t *global = malloc(sizeof(global_t));

    if (ac != 2)
        return ERROR;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return SUCCESS;
    }
    if (init_texture(texture) == ERROR)
        return ERROR;
    if (init_var(av, pars) == ERROR) {
        mini_printf("Error: file is either incorrect or non-existent.\n");
        return ERROR;
    }
    if (window_display(global, texture, window, pars->file_array) == ERROR)
        return ERROR;
    return SUCCESS;
}
