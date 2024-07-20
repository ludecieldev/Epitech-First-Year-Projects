/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #include "include.h"

//STRUCT
typedef struct window_s {
    char *name;
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    void (*__init_window__)(struct window_s *this);
    void (*__destroy_window__)(struct window_s *this);
    void (*__display_window__)(struct window_s *this);
    void (*__handle_events__)(struct window_s *this);
}window_t;

//PROTOTYPE
void init_window(window_t *this);
void destroy_window(window_t *this);
void display_window(window_t *this);
void handle_events(window_t *this);
window_t *create_window(char *name);
#endif /* !MY_PAINT_H_ */
