/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** ht_insert.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

void insert_at_index(hasharray_t **array, hasharray_t *item, int index)
{
    item->next = array[index];
    array[index] = item;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hasharray_t *item = malloc(sizeof(hasharray_t));
    int index = 0;

    if (item == NULL) {
        free(item);
        return 84;
    }
    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    item->key = my_strdup(key);
    item->hashkey = ht->hash(key, ht->len);
    item->value = my_strdup(value);
    item->next = NULL;
    index = item->hashkey % ht->len;
    insert_at_index(ht->array, item, index);
    return (0);
}
