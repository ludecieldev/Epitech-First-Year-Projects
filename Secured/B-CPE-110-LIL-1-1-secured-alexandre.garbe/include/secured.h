/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** secured.h
** Author:
** ludeciel
*/

#ifndef B_CPE_110_LIL_1_1_SECURED_ALEXANDRE_GARBE_SECURED_H
    #define B_CPE_110_LIL_1_1_SECURED_ALEXANDRE_GARBE_SECURED_H
    #include "include.h"
    #include "hashtable.h"

int mini_printf(char const *format, ...);
int my_getnbr(char *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
int get_ascii_value(char *str);
int int_count(int nb);
char *my_revstr(char *str);
char *my_strdup(char *str);

#endif //B_CPE_110_LIL_1_1_SECURED_ALEXANDRE_GARBE_SECURED_H
