/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** big_endian_writer.c
*/

#include "../../include/my.h"

int write_big_endian(void *data, int size, FILE *file)
{
    int bytes = 0;

    for (; size; size--)
        bytes += fwrite(&(((char *)data)[size - 1]), 1, 1, file);
    return bytes;
}
