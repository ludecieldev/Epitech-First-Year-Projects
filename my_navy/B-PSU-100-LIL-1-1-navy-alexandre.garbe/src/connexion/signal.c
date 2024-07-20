/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-navy-alexandre.garbe
** File description:
** signal.c
** Author:
** julienmarss
*/

#include "../../include/navy.h"

void open_and_write_map(char *path, char *string)
{
    int fd = open(path, O_WRONLY | O_TRUNC);

    write(fd, string, my_strlen(string));
    close(fd);
}

void handler(int sig)
{
    if ((sig == SIGUSR2)) {
    }
}

int getplayer1(int player_id)
{
    int fd;
    char buffer[100];

    signal(SIGUSR2, handler);
    mini_printf("my_pid: %d\n", player_id);
    mini_printf("\nwaiting for enemy...\n");
    pause();
    fd = open("player_id", O_RDONLY);
    read(fd, buffer, 100);
    close(fd);
    mini_printf("\nenemy connected\n");
    return my_getnbr(buffer);
}

int getplayer2(int player_id, int player_one_id)
{
    signal(SIGUSR1, handler);
    open_and_write_map("player_id", my_itoa(player_id));
    mini_printf("my_pid: %d\n", player_id);
    if (kill(player_one_id, SIGUSR2) == -1)
        return 84;
    mini_printf("\nsuccessfully connected to enemy\n");
    return player_one_id;
}
