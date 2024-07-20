/*
** EPITECH PROJECT, 2023
** B-CPE-101-LIL-1-1-miniprintf-alexandre.garbe
** File description:
** mini_printf
*/

#include "my_hunter.h"

int format_integer(int i, char const *format, va_list list, int count)
{
    if (format[i + 1] == 'd')
        return (my_put_nbr(va_arg(list, int)));
    if (format[i + 1] == 'i')
        return (my_put_nbr(va_arg(list, int)));
    return (0);
}

int format_string(int i, char const *format, va_list list , int count)
{
    if (format[i + 1] == 's')
        return (my_putstr(va_arg(list, char *)));
    return (0);
}

int format_char(int i, char const *format, va_list list, int count)
{
    if (format[i + 1] == 'c'){
        my_putchar(va_arg(list, int));
        count++;
        return (count - 7);
    }
    return (0);
}

int format_modulo(int i, char const *format, va_list list, int count)
{
    if (format[i + 1] == '%'){
        my_putchar('%');
        count++;
        return (count);
    }
    return (0);
}

int mini_printf(char const *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            count += format_integer(i, format, list, count);
            count += format_string(i, format, list, count);
            count += format_char(i, format, list, count);
            count += format_modulo(i, format, list, count);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(list);
    return 0;
}
