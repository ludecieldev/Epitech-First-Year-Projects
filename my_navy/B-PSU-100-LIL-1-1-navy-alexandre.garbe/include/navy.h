/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** navy.h
** Author:
** ludeciel
*/

#ifndef B_PSU_100_LIL_1_1_NAVY_ALEXANDRE_GARBE_NAVY_H
    #define B_PSU_100_LIL_1_1_NAVY_ALEXANDRE_GARBE_NAVY_H
    #include "include.h"

// Structures
typedef struct boat_s {
    int size;
    int let1;
    int num1;
    int let2;
    int num2;
    bool isVertical;
} boat_t;

typedef struct navy_s {
    char **user_map;
    char **enemy_map;
    char **blank_map;
    char **save_umap;
    char **pos;
    bool GameIsFinished;
} navy_t;

// Libraries
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char *str);
int mini_printf(char const *format, ...);
void help(void);
int my_strcmp(char *s1, char *s2);
int is_a_number(char c);
char **str_to_wordarray(char *str, char separator);
char *my_revstr(char *str);
char *my_itoa(int nbr);
void my_swap(int *a, int *b);
// Sources
int error_pos_handling(char *str);
int converter(char c);
int add_boat(boat_t **boats, char *str, int i);
int get_pos(char *filepath, boat_t **boats);
char **create_blank_map(void);
char **map_placer(boat_t **boats);
void print_map(navy_t *navy);
int getplayer2(int player_id, int player_one_id);
int getplayer1(int player_id);
int game_loop(navy_t *navy);
int get_attack(void);

#endif //B_PSU_100_LIL_1_1_NAVY_ALEXANDRE_GARBE_NAVY_H
