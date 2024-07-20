/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct hasharray_s {
    char *key;
    int hashkey;
    char *value;
    struct hasharray_s *next;
} hasharray_t;

typedef struct hashtable_s {
    int len;
    int (*hash)(char *, int);
    hasharray_t **array;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
