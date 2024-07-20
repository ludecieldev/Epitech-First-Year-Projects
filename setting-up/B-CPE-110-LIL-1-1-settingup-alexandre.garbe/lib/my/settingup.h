/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-settingup-alexandre.garbe
** File description:
** settingup
*/

#ifndef SETTINGUP_H
    #define SETTINGUP_H
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/syscall.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

typedef struct values_s {
    int cols;
    int rows;
    char **map;
    int max_size;
    int max_i;
    int max_j;
    int gen_size;
    char *filepath;
} values_t;

int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int mini_printf(char const *format, ...);
int my_strlen(char const *str);
char **my_str_to_word_array(char *str);
int find_nb_lines(char *str);
int find_nb_cols(char *str);
char find_lower(char x, char y, char z);
char **map_solving(char **map);
char **map_fl_replace(char **map);
char **map_load(char *filepath);
long int file_size(char *filepath);
char **map_from_string(char *str);
void find_and_mark_largest_square(values_t *values);
int error_handling(char *str);




#endif //SETTINGUP_H//
