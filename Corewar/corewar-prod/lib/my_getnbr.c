/*
** EPITECH PROJECT, 2023
** Day_04
** File description:
** Placeholder
*/

#include "lib.h"

int verif(int neg, long result)
{
    if (neg % 2 == 1) {
        result *= -1;
    }
    if (result < -2147483648 || result > 2147483647) {
        result = 0;
    }
    return result;
}

long my_getnbr2(char const *str, int i, long result)
{
    if (str[i] <= 47 || str[i] >= 58) {
        return result;
    }
    while (str[i] > 47 && str[i] < 58) {
        result *= 10;
        result += str[i] - '0';
        i++;
        if (result < -2147483648 || result > 2147483648) {
            result = 0;
            return result;
        }
    }
    return result;
}

int my_getnbr(char const *str)
{
    int i;
    long result;
    int neg;

    i = 0;
    neg = 0;
    result = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            neg++;
        }
        i++;
    }
    result = my_getnbr2(&str[0], i, result);
    result = verif(neg, result);
    return result;
}
