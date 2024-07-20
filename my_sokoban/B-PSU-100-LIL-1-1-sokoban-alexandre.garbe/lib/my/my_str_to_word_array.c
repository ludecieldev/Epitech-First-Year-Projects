/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** my_str_to_word_array.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

int find_max_cols(char *str)
{
    int max_cols = 0;
    int tmp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        tmp++;
        if (str[i] == '\n' || str[i + 1] == '\0') {
            max_cols = (tmp > max_cols) ? tmp : max_cols;
            tmp = 0;
        }
    }
    return max_cols;
}

int find_total_lines(char *str)
{
    int total_lines = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            total_lines++;
        }
        i++;
    }
    if (i > 0 && str[i - 1] != '\n')
        total_lines++;
    return total_lines;
}

void init_stw(str_to_word_array_t *stw, char *str)
{
    stw->nb_cols = find_max_cols(str);
    stw->i = 0;
    stw->j = 0;
    stw->k = 0;
    stw->line_length = 0;
}

static void str_short(str_to_word_array_t *stw, char **array, char *str)
{
    for (stw->i = 0; stw->i < stw->nb_lines; stw->i++) {
        array[stw->i] = malloc(sizeof(char) * (stw->nb_cols + 2));
        stw->line_length = 0;
        while (str[stw->k] != '\n' && str[stw->k] != '\0') {
            array[stw->i][stw->line_length] = str[stw->k];
            stw->line_length++;
            stw->k++;
        }
        for (stw->j = stw->line_length; stw->j < stw->nb_cols; stw->j++)
            array[stw->i][stw->j] = ' ';
        array[stw->i][stw->nb_cols] = '\n';
        array[stw->i][stw->nb_cols + 1] = '\0';
        if (str[stw->k] == '\n')
            stw->k++;
    }
}

char **my_str_to_word_array(char *str)
{
    str_to_word_array_t stw;
    char **array;

    stw.nb_lines = find_total_lines(str);
    array = malloc(sizeof(char *) * (stw.nb_lines + 1));
    if (!array)
        return NULL;
    init_stw(&stw, str);
    str_short(&stw, array, str);
    array[stw.nb_lines] = NULL;
    return array;
}
