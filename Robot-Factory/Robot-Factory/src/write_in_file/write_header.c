/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** write_header.c
*/

#include "../../include/my.h"

void reverse_size(header_t *header)
{
    char *tmp = (char *)(&(header->prog_size));
    int tmp_i = 0;

    for (int i = 0; i < 4; ++i) {
        tmp_i <<= 8;
        tmp_i += tmp[i];
    }
    header->prog_size = tmp_i;
}

void write_header(header_t *header, FILE *output)
{
    reverse_size(header);
    fseek(output, 0, SEEK_SET);
    fwrite(header, sizeof(header_t), 1, output);
}
