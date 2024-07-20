/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** error_handling.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

static int is_a_recievable_char(char c)
{
    if (c == TOWER || c == PLANE || c == SPACE || c == NEW_LINE ||
        c == END_OF_FILE || is_a_num(c) == 0)
        return SUCCESS;
    return ERROR;
}

static int string_validity(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (is_a_recievable_char(str[i]) == ERROR)
            return ERROR;
        if (str[i] == TOWER && str[i + 1] == TOWER)
            return ERROR;
        if (str[i] == PLANE && str[i + 1] == PLANE)
            return ERROR;
    }
    return SUCCESS;
}

static int planes_and_towers(char *str, parsing_t *pars)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == TOWER)
            pars->nb_tower++;
        if (str[i] == PLANE)
            pars->nb_plane++;
    }
    if (pars->nb_plane == 0 || pars->nb_tower == 0)
        return ERROR;
    return SUCCESS;
}

int error_handling(char *str, parsing_t *pars)
{
    if (string_validity(str) == ERROR)
        return ERROR;
    if (planes_and_towers(str, pars) == ERROR)
        return ERROR;
    return SUCCESS;
}
