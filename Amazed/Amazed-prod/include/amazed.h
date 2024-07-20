/*
** EPITECH PROJECT, 2024
** Amazed-prod
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdbool.h>
//STRUCT
typedef struct info_s {
    int number_of_rooms;
    int number_of_robots;
} info_t;


typedef struct room_s {
    int x;
    int y;
    char *name;
    bool isOccupied;
    struct room_s *prev;
    struct room_s *next;
    struct link_s *links;
    void (*__add_room__)(struct room_s *this, struct room_s *new);
    void (*__remove_room__)(struct room_s *this, char *name);
    void (*__print_rooms__)(struct room_s *this);
    void (*__free_room__)(struct room_s *this);
} room_t;
typedef struct link_s {
    char *name;
    struct room_s *room;
    struct link_s *next;
} link_t;

//FUNC
void *my_memset(void *s, int c, size_t n);
char *my_itoa(int nbr);
int my_getnbr(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
char **str_to_wordarray(char *str, char separator);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *str);
char *my_revstr(char *str);
int my_arraylen(char **array);
char *my_strcat(char *dest, char *src);
void puterror(char *str);
char *my_realloc(char *str, int size);
char **my_realloc_array(char **array, char *str);
char **my_arraydup(char **array);
int my_str_contains(char *str, char c);
char *my_strcpy(char *dest, char *src);
//SRC
void add_room(struct room_s *room, struct room_s *new);
void remove_room(struct room_s *room, char *name);
room_t *create_list(char *name, int x, int y);
void free_room(struct room_s *room);
void print_room(room_t *room);
int parser(void);
int file_reader(void);

#endif /* !AMAZED_H_ */
