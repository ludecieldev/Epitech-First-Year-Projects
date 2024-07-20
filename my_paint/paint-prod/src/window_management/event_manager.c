/*
** EPITECH PROJECT, 2024
** paint-prod
** File description:
** event_manager
*/

#include "window.h"

void handle_events(window_t *this)
{
    while (sfRenderWindow_pollEvent(this->window, &(this->event))) {
        if (this->event.type == sfEvtClosed)
            sfRenderWindow_close(this->window);
        if (this->event.type == sfEvtResized)
            sfView_setSize(this->view, (sfVector2f){this->event.size.width,
                this->event.size.height});
    }
}
