/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** get_adress.c
*/

#include "corewar.h"

char *get_address(char *mem, char const *address)
{
    while (address < mem)
        address += (long)mem;
    return mem + ((address - mem) % MEM_SIZE);
}
