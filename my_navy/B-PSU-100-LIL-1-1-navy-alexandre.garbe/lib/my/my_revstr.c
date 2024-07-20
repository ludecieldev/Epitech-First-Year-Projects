/*
** EPITECH PROJECT, 2023
** project my_navy
** File description:
** my_putstr
*/

char *my_revstr(char *str)
{
    char temp;
    int a = 0;
    int b = 0;

    while (str[a] != '\0')
        a++;
    a--;
    while (b < a) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        a--;
        b++;
    }
    return str;
}
