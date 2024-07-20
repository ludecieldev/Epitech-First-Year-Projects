/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-alexandre.garbe
** File description:
** parser.c
** Author:
** ludeciel
*/

#include "../../include/my_radar.h"

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

char **array_from_string(char *str)
{
    char **array = my_str_to_word_array(str);

    return (array);
}

static void count_planes_and_towers(char *str, parsing_t *pars)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == TOWER)
            pars->nb_tower++;
        if (str[i] == PLANE)
            pars->nb_plane++;
    }
}

char **load_file(char *filepath, parsing_t *parsing)
{
    int fd = open(filepath, O_RDONLY);
    off_t size = file_size(filepath);
    char *buffer;

    if (fd == -1 || size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (!buffer)
        return NULL;
    if (read(fd, buffer, size) == -1)
        return NULL;
    buffer[size] = '\0';
    if (error_handling(buffer, parsing) == ERROR)
        return NULL;
    count_planes_and_towers(buffer, parsing);
    close(fd);
    return (array_from_string(buffer));
}
