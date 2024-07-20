/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** my_strtok.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

static int word_len(char *str, char delim)
{
    int len = 0;

    for (int i = 0; str[i] != '\0' && str[i] != delim; i++)
        len++;
    return len;
}

char *str_set(int size)
{
    char *ptr = malloc(sizeof(char) * (size + 1));

    if (!ptr)
        return NULL;
    if (!size)
        return NULL;
    for (int i = 0; i < size + 1; i++)
        ptr[i] = 0;
    ptr[size] = '\0';
    return ptr;
}

static char **get_token(char *str, int wordcount, char delim)
{
    char **array = malloc(sizeof(char *) * (wordcount + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    if (!array)
        return NULL;
    for (i = 0; i < wordcount; i++) {
        array[i] = str_set(word_len(&str[k], delim) + 1);
        for (j = 0; str[k] != '\0' && str[k] != delim; j++) {
            array[i][j] = str[k];
            k++;
        }
        array[i][j] = '\0';
        k++;
    }
    array[i] = NULL;
    return array;
}

char **my_strtok(char *str, char delim)
{
    int wordcount = count_words(str, delim);

    return get_token(str, wordcount, delim);
}
