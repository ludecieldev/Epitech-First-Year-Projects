/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** main.c
*/

#include "../../include/my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
}

void free_file(char ***file_tab)
{
    for (int i = 0; file_tab[i]; i++) {
        free_tab(file_tab[i]);
        free(file_tab[i]);
    }
    free(file_tab);
}

int start(header_t *header, char *output_name, char ***file_tab)
{
    list_t **labels;
    char ***body;
    FILE *output;

    if (error_handling(file_tab) == 84)
        return 84;
    output = get_output_file(output_name);
    body = &(file_tab[1 + (file_tab[1] &&
        my_strcmp(".comment\0", file_tab[1][0]) == 0)]);
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    parse_header(file_tab, header, output);
    labels = get_labels(body);
    if (!labels)
        return 84;
    parse_body(body, header, output, *labels);
    write_header(header, output);
    fclose(output);
    return 0;
}

int main(int ac, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    FILE *input;
    char ***file_tab;

    if (ac != 2)
        return 84;
    input = fopen(av[1], "r");
    if (!input)
        return 84;
    file_tab = parse_file(input);
    if (start(header, av[1], file_tab) == 84)
        return 84;
    free_file(file_tab);
    free(header);
    fclose(input);
    return 0;
}
