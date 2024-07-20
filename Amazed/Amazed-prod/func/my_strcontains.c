/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** my_str_contains
*/

int my_str_contains(char *str, char c)
{
    if (!str)
        return 0;
    if (c == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c && str[i + 1] != '"' && str[i - 1] != '"')
            return 1;
    return 0;
}
