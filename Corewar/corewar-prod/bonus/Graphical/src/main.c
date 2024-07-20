/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** main.c
*/

#include "corewar.h"
#include "memory_meta.h"

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

int determine_color(memory_meta_t meta) {
    // Simple example: color based on owner
    return meta.owner_id + 1;  // Assuming color pair IDs match owner IDs
}

void dump_mem(WINDOW *win, char *mem, memory_meta_t *meta)
{
    werase(win);
    int line = 1;
    int col = 1;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            mvwprintw(win, line++, 1, "%04x:", i);
            col = 10;
        }
        int color_pair = determine_color(meta[i]);
        wattron(win, COLOR_PAIR(color_pair));
        wprintw(win, " %02x", (unsigned char)mem[i]);
        wattroff(win, COLOR_PAIR(color_pair));
        col += 3;

        if (col >= 70) {
            line++;
            col = 1;
        }
    }
    wrefresh(win);
}

memory_meta_t init_meta(void)
{
    memory_meta_t meta[MEM_SIZE];

    for (int i = 0; i < MEM_SIZE; i++) {
        meta[i].owner_id = -1;
        meta[i].last_access_cycle = 0;
        meta[i].last_access_type = 0;
    }
    return *meta;
}

int main(int ac, char **av)
{
    parsing_t *parse = parsing(ac, av);
    corewar_t *corewar;
    memory_meta_t meta = init_meta();

    init_ncurses();
    if (parse->error == 84) {
        free_parsing(parse);
        return 84;
    }
    corewar = setup_corewar(parse);
    if (!corewar) {
        free_parsing(parse);
        return 84;
    }
    corewar_loop(corewar, &meta);
    free_parsing(parse);
    endwin();
    return 0;
}
