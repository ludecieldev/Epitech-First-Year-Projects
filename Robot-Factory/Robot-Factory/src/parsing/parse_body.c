/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** parse_body.c
*/

#include "../../include/my.h"

int show_param(int op, char *param, header_t *header, FILE *file)
{
    unsigned int b4;
    unsigned short b2;
    unsigned char b1;

    if (get_arg_type(param) == 2 && IS_4BYTES_DIR(op_tab[op].code)) {
        b4 = my_getnbr_plus(&(param[1]));
        header->prog_size += write_big_endian(&b4, 4, file);
    }
    if (get_arg_type(param) == 1) {
        b1 = my_getnbr_plus(&(param[1]));
        header->prog_size += write_big_endian(&b1, 1, file);
    }
    if (get_arg_type(param) == 3 || (get_arg_type(param) == 2 &&
        (IS_2BYTES_DIR(op_tab[op].code)))) {
        b2 = my_getnbr_plus(&(param[get_arg_type(param) == 2]));
        header->prog_size += write_big_endian(&b2, 2, file);
    }
    return 0;
}

static int search_in_list(char *label, list_t *labels)
{
    for (; labels; labels = labels->next) {
        if (my_strcmp(label, ((labels_t *)(labels->value))->name) == 0)
            return ((labels_t *)(labels->value))->position;
    }
    return 0;
}

static void search_label(int op, char *label, info_t *infos, list_t *labels)
{
    int label_pos = search_in_list(label, labels);
    int diff_i = label_pos - infos->size;
    short diff_s = (short)(label_pos - infos->size);

    if (IS_2BYTES_DIR(op_tab[op].code))
        infos->header->prog_size += write_big_endian(&diff_s, 2, infos->file);
    else
        infos->header->prog_size += write_big_endian(&diff_i, 4, infos->file);
}

int do_instruction(int op, char **line, info_t *infos, list_t *labels)
{
    unsigned char types = 0;

    infos->size = infos->header->prog_size + 1;
    infos->header->prog_size += write_big_endian(&(op_tab[op].code),
        1, infos->file);
    for (int i = 0; i < op_tab[op].nbr_args; i++) {
        types += (unsigned char)get_arg_type(line[i + 1]) << (2 * (3 - i));
    }
    if (HAS_SPEC(op_tab[op].code))
        infos->header->prog_size += write_big_endian(&types, 1, infos->file);
    for (int i = 0; i < op_tab[op].nbr_args; i++) {
        if (!is_label(line[i + 1]))
            show_param(op, line[i + 1], infos->header, infos->file);
        else
            search_label(op, line[i + 1] + 2, infos, labels);
    }
    return 0;
}

int parse_line(char **line, info_t *infos, list_t *labels)
{
    if (line[0][my_strlen(line[0]) - 1] == ':')
        line++;
    if (!*line)
        return 0;
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(line[0], op_tab[i].mnemonique) == 0 &&
            my_listlen(line) == op_tab[i].nbr_args + 1)
            do_instruction(i, line, infos, labels);
    }
    return 0;
}

int parse_body(char ***body, header_t *header, FILE *file, list_t *labels)
{
    info_t *infos = malloc(sizeof(info_t));

    infos->file = file;
    infos->header = header;
    for (int i = 0; body[i]; i++) {
        parse_line(body[i], infos, labels);
    }
    free(infos);
    return 0;
}
