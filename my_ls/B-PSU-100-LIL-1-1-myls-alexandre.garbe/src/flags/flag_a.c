/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** flag_a
*/

#include "../../lib/my/my.h"

int flag_a(char const *path)
{
    DIR *dir;
    struct dirent *dirent;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    dirent = readdir(dir);
    while (dirent){
        mini_printf("%s  ", dirent->d_name);
        dirent = readdir(dir);
    }
    closedir(dir);
    return 0;
}
