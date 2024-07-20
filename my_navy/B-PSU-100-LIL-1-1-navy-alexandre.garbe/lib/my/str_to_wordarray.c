/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** str_to_wordarray.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int count_words(char *str, char separator)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == separator)
            count++;
        i++;
    }
    return (count + 1);
}

int count_letters(char *str, char separator)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != separator)
        i++;
    return (i);
}

char **str_to_wordarray(char *str, char separator)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count_words(str, separator) + 1));

    while (str[i] != '\0') {
        array[j] = malloc(sizeof(char) * (count_letters(str, separator) + 1));
        while (str[i] != '\0' && str[i] != separator) {
            array[j][k] = str[i];
            i++;
            k++;
        }
        array[j][k] = '\0';
        k = 0;
        if (str[i] != '\0')
            i++;
        j++;
    }
    array[j] = NULL;
    return (array);
}
