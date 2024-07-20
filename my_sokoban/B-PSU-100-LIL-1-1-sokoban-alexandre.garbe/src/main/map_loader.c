/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-alexandre.garbe
** File description:
** map_loader.c
** Author:
** ludeciel
*/

#include "../../include/sokoban.h"

long int file_size(char *filepath)
{
    struct stat st;

    stat(filepath, &st);
    if (S_ISDIR(st.st_mode))
        return (-1);
    if (st.st_size == 0 || st.st_size == -1)
        return (-1);
    return (st.st_size);
}

char **map_from_string(char *str)
{
    char **map = my_str_to_word_array(str);

    return (map);
}

char **map_load(char *filepath, map_info_t *map_info)
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
    if (get_info(map_file, map_info) == 84)
        return (NULL);
    close(fd);
    return (map_from_string(map_file));
}
