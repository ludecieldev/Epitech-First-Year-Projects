/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main.c
** Author:
** ludeciel
*/

#include "../../include/navy.h"

int main_init(int ac, char **av, navy_t *navy, boat_t **boats)
{
    int pid = getpid();

    if (ac == 2) {
        if (get_pos(av[1], boats) == 84) {
            return (84);
        }
        getplayer1(pid);
        navy->user_map = map_placer(boats);
    }
    if (ac == 3) {
        if (get_pos(av[2], boats) == 84) {
            return (84);
        }
        getplayer2(pid, my_getnbr(av[1]));
        navy->user_map = map_placer(boats);
    }
    navy->enemy_map = create_blank_map();
    return (0);
}

int main(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(navy_t));
    boat_t **boats = malloc(sizeof(boat_t) * 4);

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
    }
    if (ac != 2 && ac != 3) {
        mini_printf("Wrong number of arguments\n");
        free(navy);
        return (84);
    }
    if (main_init(ac, av, navy, boats) == 84) {
        mini_printf("Wrong file\n");
        free(navy);
        return (84);
    }
    game_loop(navy);
}
