/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** new_hastable.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (ht == NULL || len <= 0) {
        free(ht);
        return NULL;
    }
    ht->len = len;
    ht->hash = hash;
    ht->array = malloc(sizeof(hasharray_t *) * len);
    for (int i = 0; i < len; i++)
        ht->array[i] = NULL;
    return (ht);
}
