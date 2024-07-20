/*
** EPITECH PROJECT, 2024
** lib
** File description:
** lib.h
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <time.h>
    #include <string.h>
    #include <fcntl.h>

char **my_better_str_to_word_array(char const *str);
int is_anum(char c);
int my_getnbr(char const *str);
void my_bzero(char *str, long size);
int my_atoi(char *str);
void my_putnbr(long nb);
char *my_nb_to_str(int nb);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
int is_lower(char c);
int is_upper(char c);
int is_num(char c);
int count_words(char const *str);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strdup(char *src);
char *my_revstr(char *str);
char *my_strlowcase(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase(char *str);
unsigned int my_getnbr_plus(char const *str);
#endif
