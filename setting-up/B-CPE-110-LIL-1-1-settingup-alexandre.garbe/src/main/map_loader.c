/*
** EPITECH PROJECT, 2023
** settingup
** File description:
** map_loader.c
** Author:
** ludeciel
*/

#include "../../lib/my/settingup.h"

int error_handling(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (84);
        }
        count++;
    }
    for (int i = count + 1; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != 'o' && str[i] != '\n')
            return (84);
    }
    if (str[0] == '\n')
        return (84);
    return (0);
}

long int file_size(char *filepath)
{
    struct stat st;

    stat(filepath, &st);
    if (st.st_size == -1)
        return (-1);
    return (st.st_size);
}

char **map_from_string(char *str)
{
    char **map = my_str_to_word_array(str);

    return (map);
}

char **map_load(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t size = file_size(filepath);
    char *map_file;

    if (fd == -1 || size == -1){
        return (NULL);
    }
    map_file = malloc(sizeof(char) * (size + 1));
    if (!map_file) {
        return (NULL);
    }
    if (read(fd, map_file, size) == -1) {
        return (NULL);
    }
    map_file[size] = '\0';
    close(fd);
    if (error_handling(map_file) == 84)
        return (NULL);
    return (map_from_string(map_file));
}
