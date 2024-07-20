/*
** EPITECH PROJECT, 2024
** corewar-prod
** File description:
** memory_meta
*/

#ifndef MEMORY_META_H_
    #define MEMORY_META_H_
    #include "op.h"
typedef struct {
    int owner_id;
    int last_access_cycle;
    char last_access_type;
} memory_meta_t;

memory_meta_t memory_metadata[MEM_SIZE];
#endif /* !MEMORY_META_H_ */
