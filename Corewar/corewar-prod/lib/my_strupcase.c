/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

char *my_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] < 123 && str[i] > 96)
            str[i] -= 32;
        i++;
    }
    return str;
}
