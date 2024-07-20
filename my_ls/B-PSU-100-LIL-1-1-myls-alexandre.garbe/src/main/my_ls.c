/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** my_ls
*/

#include "../../lib/my/my.h"

int my_ls(char *path)
{
    DIR *dir;
    struct dirent *dirent;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    dirent = readdir(dir);
    if (dirent == NULL)
        return 84;
    while (dirent){
        if (dirent->d_name[0] != '.'){
            mini_printf("%s  ", dirent->d_name);
        }
        dirent = readdir(dir);
    }
    closedir(dir);
    return 0;
}
