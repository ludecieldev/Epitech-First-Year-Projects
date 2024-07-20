/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** parse_file.c
*/

#include "../../include/my.h"

int line_is_empty(char const *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '#')
            return 1;
        if (is_anum(line[i]))
            return 0;
    }
    return 1;
}

int count_lines(FILE *file)
{
    char *line = 0;
    size_t size;
    int i = 0;

    for (; getline(&line, &size, file) > 0;) {
        if (line[0] == COMMENT_CHAR || line[0] == '\n' || line_is_empty(line))
            continue;
        i++;
    }
    free(line);
    return i;
}

char ***parse_file(FILE *file)
{
    char *line = 0;
    size_t size;
    char ***line_tab = malloc(sizeof(char **) * (count_lines(file) + 1));
    char **line_array;
    int index = 0;

    fseek(file, 0, SEEK_SET);
    for (; getline(&line, &size, file) > 0;) {
        if (line[0] == COMMENT_CHAR || line[0] == '\n' || line_is_empty(line))
            continue;
        line_array = my_better_str_to_word_array(line);
        line_tab[index] = line_array;
        index++;
    }
    line_tab[index] = 0;
    free(line);
    return line_tab;
}
