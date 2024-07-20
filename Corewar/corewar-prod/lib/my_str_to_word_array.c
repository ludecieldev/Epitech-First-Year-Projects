/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Placeholder
*/

#include "lib.h"

int is_anum(char c)
{
    return c != ' ' && c != '\n' && c != '\t';
}

int count_words(char const *str)
{
    int count = 0;
    int i = 0;

    if (is_anum(str[i]))
        count++;
    while (str[i] != '\0' && str[i + 1] != '\0') {
        while (!(is_anum(str[i + 1])) && str[i + 1] != '\0')
            i++;
        if (!(is_anum(str[i])) && str[i + 1] != '\0')
            count++;
        i++;
    }
    return count;
}

void modify_str(char const *str, char **str2)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;
    int found_letter = 0;

    my_strcpy(new_str, str);
    for (; i < my_strlen(str); i++)
        new_str[i] -= new_str[i] * !(is_anum(str[i]));
    i = 0;
    for (; str[i]; i++) {
        if (new_str[i] != '\0' && found_letter == 0) {
            str2[j] = malloc(my_strlen(&new_str[i]) + 1);
            my_strcpy(str2[j], &new_str[i]);
            j++;
            found_letter = 1;
        }
        if (new_str[i] == '\0')
            found_letter = 0;
    }
    free(new_str);
}

char **my_str_to_word_array(char const *str)
{
    char **str2 = malloc(sizeof(char *) * (count_words(str) + 1));

    for (int i = 0; i <= count_words(str); i++)
        str2[i] = 0;
    modify_str(str, str2);
    return str2;
}
