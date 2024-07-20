/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex7_2.c
*/

#include "list.h"

void map_clear(map_t **map_ptr)
{
    list_clear((list_t **)map_ptr);
}
