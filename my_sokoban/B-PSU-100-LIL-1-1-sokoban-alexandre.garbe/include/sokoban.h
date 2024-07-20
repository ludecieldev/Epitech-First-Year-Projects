/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** sokoban.h
** Author:
** ludeciel
*/


#ifndef B_PSU_100_LIL_1_1_SOKOBAN_ALEXANDRE_GARBE_SOKOBAN_H
    #define B_PSU_100_LIL_1_1_SOKOBAN_ALEXANDRE_GARBE_SOKOBAN_H
    #include <ncurses.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdbool.h>

typedef struct map_info {
    int nb_cols;
    int nb_rows;
    int nb_boxes;
    int nb_storage;
    int nb_player;
    char **map;
    char **map_origin;
} map_info_t;

typedef struct player_info {
    int x;
    int y;
    int x_origin;
    int y_origin;
} player_info_t;

typedef struct storage_info {
    int x;
    int y;
} storage_info_t;

typedef struct party_info {
    int nb_moves;
    bool GameIsOver;
    bool GameIsWon;
    int ch;
    player_info_t player;
} party_info_t;

typedef struct str_to_word_array_s {
    int nb_lines;
    int nb_cols;
    int i;
    int j;
    int k;
    int line_length;
} str_to_word_array_t;

int find_nb_lines(char *str);
int find_nb_cols(char *str);
char **my_str_to_word_array(char *str);
int my_sokoban(char **map);
long int file_size(char *filepath);
char **map_from_string(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int mini_printf(char const *format, ...);
int format_integer(int i, char const *format, va_list list, int count);
int format_string(int i, char const *format, va_list list , int count);
int format_char(int i, char const *format, va_list list, int count);
int format_modulo(int i, char const *format, va_list list, int count);
int my_putstr(char const *str);
int my_strlen(char const *str);
int get_info(char *map, map_info_t *map_info);
char **map_load(char *filepath, map_info_t *map_info);
void display_map(char **map);
void game(map_info_t *map, player_info_t *player, party_info_t *party_info);
void find_player(map_info_t *mapInfo, player_info_t *player);
void cond_break(map_info_t *mapInfo, int i, int j, player_info_t *player);
void pl_mv(party_info_t *pty_info, player_info_t  *pl, map_info_t *map_info);
void move_up(map_info_t *map_info, player_info_t *player);
void move_down(map_info_t *map_info, player_info_t *player);
void move_left(map_info_t *map_info, player_info_t *player);
void move_right(map_info_t *map_info, player_info_t *player);
void replace_storage(map_info_t *map_info, player_info_t *player);
void reset_map(map_info_t *mapinfo, player_info_t *player);
void victory_loss_management(map_info_t *map_info, party_info_t *party_info);

#endif //B_PSU_100_LIL_1_1_SOKOBAN_ALEXANDRE_GARBE_SOKOBAN_H
