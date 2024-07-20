/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** main.c
*/

#include "corewar.h"

static void my_putnbr_hex(int nbr)
{
    int base_nb = 16;
    char str[100] = {0};
    int i = 0;
    char base[16] = "0123456789ABCDEF";

    if (nbr == 0) {
        write(1, "0", 1);
        return;
    }
    while (nbr != 0) {
        str[i] = base[nbr % base_nb];
        nbr /= base_nb;
        i++;
    }
    my_revstr(str);
    write(1, str, my_strlen(str));
}

static void hex_print(unsigned char c)
{
    int base_nb;
    char base[16] = "0123456789ABCDEF";
    char str[3] = {'0', '0', 0};
    int i = 0;

    if (c == 0) {
        write(1, "00", 2);
        return;
    }
    base_nb = 16;
    while (c != 0) {
        str[i] = base[c % base_nb];
        c /= base_nb;
        i++;
    }
    my_revstr(str);
    write(1, str, 2);
}

void dump_mem(char *mem)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            my_putnbr_hex(i);
            write(1, "\t:", 2);
        }
        write(1, " ", 1);
        hex_print(mem[i]);
        if ((i + 1) % 32 == 0)
            write(1, "\n", 1);
    }
}

static void free_corewar(corewar_t *corewar)
{
    for (u_int i = 0; i < corewar->champ_nb; i++) {
        for (u_int j = 0; j < corewar->champions[i]->process_nb; j++) {
            free(corewar->champions[i]->process[j]->param);
            free(corewar->champions[i]->process[j]);
        }
        free(corewar->champions[i]->champ_code);
        free(corewar->champions[i]);
    }
    free(corewar->champions);
    free(corewar);
}

int main(int ac, char **av)
{
    parsing_t *parse = parsing(ac, av);
    corewar_t *corewar;

    if (parse->error == 84) {
        free_parsing(parse);
        return 84;
    }
    corewar = setup_corewar(parse);
    if (!corewar) {
        free_parsing(parse);
        return 84;
    }
    corewar_loop(corewar);
    free_corewar(corewar);
    free_parsing(parse);
    return 0;
}
