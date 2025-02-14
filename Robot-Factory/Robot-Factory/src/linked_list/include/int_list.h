/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises 00, 01, 02 & 03
*/

#ifndef INT_LIST
    #define INT_LIST
    #include <stdbool.h>

typedef struct int_list_s {
    int value;
    struct int_list_s *next;
} int_list_t;
unsigned int int_list_get_size(int_list_t *list);
bool int_list_is_empty(int_list_t *list);
void int_list_dump(int_list_t *list);
bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem);
bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem);
bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position);
bool int_list_del_elem_at_front(int_list_t **front_ptr);
bool int_list_del_elem_at_back(int_list_t **front_ptr);
bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position);
void int_list_clear(int_list_t **front_ptr);
int int_list_get_elem_at_front(int_list_t *list);
int int_list_get_elem_at_back(int_list_t *list);
int int_list_get_elem_at_position(int_list_t *list,
    unsigned int position);
void my_putnbr(long nb);
#endif
