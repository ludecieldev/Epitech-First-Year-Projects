/*
** EPITECH PROJECT, 2024
** B-CPE-110-LIL-1-1-secured-alexandre.garbe
** File description:
** delete_hashtable.c
** Author:
** ludeciel
*/

#include "../../include/secured.h"

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; i++) {
        if (ht->array[i]) {
            free(ht->array[i]->key);
            free(ht->array[i]->value);
            free(ht->array[i]);
        }
    }
    free(ht->array);
    free(ht);
}
