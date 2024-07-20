/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

char *my_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] < 91 && str[i] > 64)
            str[i] += 32;
        i++;
    }
    return str;
}
