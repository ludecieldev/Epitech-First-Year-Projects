/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** my_str_to_word_array.c
** Author:
** ludeciel
*/

#include "settingup.h"

int find_nb_lines(char *str)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            nb_lines++;
    return (nb_lines);
}

int find_nb_cols(char *str)
{
    int nb_cols = 0;
    int count = 0;

    for (count = 0; str[count] != '\n'; count++);
    for (int i = count + 1; str[i] != '\n'; i++)
        nb_cols++;
    return (nb_cols);
}

char **my_str_to_word_array(char *str)
{
    int nb_lines = find_nb_lines(str);
    int nb_cols = find_nb_cols(str);
    char **array = malloc(sizeof(char *) * (nb_lines + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; str[k - 1] != '\n'; k++);
    for (i = 0; i < nb_lines; i++) {
        array[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (j = 0; j < nb_cols; j++) {
            array[i][j] = str[k];
            k++;
        }
        array[i][j] = '\0';
        k++;
    }
    array[i] = NULL;
    return array;
}
