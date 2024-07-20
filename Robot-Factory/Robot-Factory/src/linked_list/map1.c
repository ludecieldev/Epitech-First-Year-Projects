/*
** EPITECH PROJECT, 2024
** day04_tek2
** File description:
** ex7.c
*/

#include "list.h"

unsigned int map_get_size(map_t *map)
{
    return list_get_size((list_t *)map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty((list_t *)map);
}

bool map_add_elem(map_t **map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    map_t *head;
    pair_t *new;

    if (!map_ptr)
        return false;
    new = malloc(sizeof(pair_t));
    new->key = key;
    new->value = value;
    head = *map_ptr;
    for (int i = 0; head; head = head->next) {
        if (key_cmp(((pair_t *)head->value)->key, key) == 0) {
            ((pair_t *)head->value)->value = value;
            free(new);
            return true;
        }
        if (key_cmp(((pair_t *)head->value)->key, key) < 0)
            return list_add_elem_at_position((list_t **)map_ptr, new, i);
        i++;
    }
    return list_add_elem_at_back((list_t **)map_ptr, new);
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t *head;

    if (!map_ptr || !*map_ptr)
        return false;
    head = *map_ptr;
    for (int i = 0; head; head = head->next) {
        if (key_cmp(((pair_t *)head->value)->key, key) == 0)
            return list_del_elem_at_position((list_t **)map_ptr, i);
        i++;
    }
    return false;
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    for (; map; map = map->next)
        if (key_cmp(((pair_t *)map->value)->key, key) == 0)
            return ((pair_t *)map->value)->value;
    return NULL;
}
