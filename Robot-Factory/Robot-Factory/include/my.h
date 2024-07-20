/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_robotfactory_alexandre_garbe
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include "../lib/lib.h"
    #include "op.h"
    #include "macros.h"
    #include <errno.h>
    #include "../src/linked_list/list.h"

typedef struct labels_s {
    char *name;
    int position;
} labels_t;
typedef struct info_s {
    FILE *file;
    header_t *header;
    int size;
} info_t;
void write_header(header_t *header, FILE *output);
FILE *get_output_file(char *input_name);
int my_listlen(char **list);
int my_tablen(char ***list);
char ***parse_file(FILE *file);
int parse_header(char ***file_tab, header_t *header, FILE *file);
int write_big_endian(void *data, int size, FILE *file);
int get_arg_type(char *arg);
int is_label(char *arg);
int parse_body(char ***body, header_t *header, FILE *file, list_t *labels);
list_t **get_labels(char ***body);
int error_handling(char ***parse_file);
#endif
