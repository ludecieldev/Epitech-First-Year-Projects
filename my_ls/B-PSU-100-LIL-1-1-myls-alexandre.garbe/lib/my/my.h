/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/syscall.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

typedef struct flags_s {
    char flag;
    int (*p)(char const *path);
}flags_s_t;

int mini_printf(char const *format, ...);
int format_integer(int i, char const *format, va_list list, int count);
int format_string(int i, char const *format, va_list list , int count);
int format_char(int i, char const *format, va_list list, int count);
int format_modulo(int i, char const *format, va_list list, int count);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int flag_a(char const *path);
int flag_d(char const *path);
int flag_l(char const *path);
int flag_t(char const *path);
int flag_r_min(char const *path);
int flag_r_maj(char const *path);
int my_ls(char *path);
char *flag_identifier(int ac, char **av);
void flag_checker(char **av, int *i, char const *path, int *bo);
char *pathfinder(int ac, char **av);
static void print_size(struct stat *statfile);
static void link_getter(struct stat *statfile);
static void time_getter(struct stat *statfile);
static void print_rights(struct stat *statfile);
static void flag_l_printer(struct dirent *dirent, struct stat *statfile);
void type_file_check(struct stat *statfile);
void byte_checker(struct stat *statfile);
int errorcase(int ac, char **av);


static const flags_s_t flags[] = {
    {.flag = 'a', .p = &flag_a},
    {.flag = 'l', .p = &flag_l},
    {.flag = 'd', .p = &flag_d},
    {.flag = 'r', .p = &flag_r_min},
    {.flag = 'R', .p = &flag_r_maj},
    {.flag = 't', .p = &flag_t}
};


#endif /* !MY_H_ */
