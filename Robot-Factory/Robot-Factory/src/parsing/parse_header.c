/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** parse_header.c
*/

#include "../../include/my.h"

int parse_header(char ***file_tab, header_t *header, FILE *file)
{
    if (my_strcmp(file_tab[0][0], NAME_CMD_STRING) != 0)
        return -1;
    if (my_listlen(file_tab[0]) != 2)
        return -1;
    my_strcpy(header->prog_name, file_tab[0][1]);
    if (file_tab[1] && my_strcmp(".comment\0", file_tab[1][0]) == 0)
        my_strcpy(header->comment, file_tab[1][1]);
    write_header(header, file);
    return 0;
}
