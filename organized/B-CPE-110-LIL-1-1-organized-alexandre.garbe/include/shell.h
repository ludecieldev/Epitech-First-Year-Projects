/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>


#ifndef SHELL_H
    #define SHELL_H

typedef struct linked_s {
    int id;
    char *name;
    char *type;
    struct linked_s *next;
} linked_t;

int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);
int mini_printf(char const *format, ...);
int workshop_shell(void *data);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
int my_put_nbr(int nb);
char *my_strdup(char *str);
int my_getnbr(char *str);

#endif /* SHELL_H */
