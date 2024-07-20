/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** ht_search.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    hasharray_t *array = NULL;

    if (ht == NULL || key == NULL)
        return (NULL);
    index = ht->hash(key, ht->len) % ht->len;
    array = ht->array[index];
    while (array != NULL) {
        if (my_strcmp(array->key, key) == 0)
            return (array->value);
        array = array->next;
    }
    return (NULL);
}
