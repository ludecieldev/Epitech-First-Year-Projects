/*
** EPITECH PROJECT, 2024
** create_view
** File description:
** idem
*/

#include "my_rpg.h"

/**
 * @brief Function to create a sfView
 * @param void
 * @return sfView*
*/
sfView *create_view(void)
{
    sfView *view = sfView_create();

    if (view == NULL)
        return NULL;
    return view;
}
