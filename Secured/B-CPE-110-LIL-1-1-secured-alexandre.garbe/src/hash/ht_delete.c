/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** ht_delete.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

void cond_break(hasharray_t *array, hasharray_t *prev, hashtable_t *ht,
    int index)
{
    if (prev == NULL)
        ht->array[index] = array->next;
    else
        prev->next = array->next;
    free(array);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;
    hasharray_t *array = NULL;
    hasharray_t *prev = NULL;

    if (ht == NULL || key == NULL)
        return (84);
    index = ht->hash(key, ht->len) % ht->len;
    array = ht->array[index];
    while (array != NULL) {
        if (my_strcmp(array->key, key) == 0) {
            cond_break(array, prev, ht, index);
            return 0;
        }
        prev = array;
        array = array->next;
    }
    return 84;
}
