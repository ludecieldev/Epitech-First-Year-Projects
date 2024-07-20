/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** my_better_str_to_word_array.c
*/

#include "lib.h"

int quote_count(const char *str)
{
    int quotes = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\"')
            quotes++;
    return quotes;
}

int better_count_words(const char *str)
{
    int count = 0;
    int i = 0;
    int quote_found = 0;

    if (quote_count(str) != 2)
        return count_words(str);
    if (is_anum(str[i]))
        count++;
    while (str[i] && str[i + 1]) {
        while (!is_anum(str[i + 1]) && str[i + 1])
            i++;
        if (!is_anum(str[i]) && str[i + 1] && quote_found == 0)
            count++;
        if (str[i + 1] == '\"')
            quote_found = !quote_found;
        if (!quote_found && str[i + 1] == '#')
            return count;
        i++;
    }
    return count;
}

char *get_new_str(char const *str)
{
    char *new_str = malloc(my_strlen(str) + 1);
    int found_quote = 0;
    int found_comment = 0;

    my_strcpy(new_str, str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\"') {
            found_quote = !found_quote;
            new_str[i] = 0;
            continue;
        }
        if (!found_quote && str[i] == '#')
            found_comment = 1;
        new_str[i] -= new_str[i] * ((!is_anum(str[i]) &&
            !found_quote) || found_comment);
    }
    return new_str;
}

void modify_tab(char const *str, char **ret)
{
    char *new_str = get_new_str(str);
    int j = 0;
    int found_letter = 0;

    for (int i = 0; str[i]; i++) {
        if (new_str[i] != '\0' && found_letter == 0) {
            ret[j] = my_strdup(&new_str[i]);
            j++;
            found_letter = 1;
        }
        if (new_str[i] == '\0')
            found_letter = 0;
    }
    free(new_str);
}

char **my_better_str_to_word_array(char const *str)
{
    char **ret = malloc(sizeof(char *) * (1 + better_count_words(str)));

    for (int i = 0; i <= better_count_words(str); i++)
        ret[i] = 0;
    modify_tab(str, ret);
    return ret;
}
