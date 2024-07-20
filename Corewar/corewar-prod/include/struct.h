/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include "corewar.h"

typedef int reg_t;

typedef struct parameter {
    int instr;
    int param[3];
    u_char param_info;
    void *pc;
} parameter_t;

typedef struct process {
    void *pc;
    reg_t reg[REG_NUMBER];
    _Bool carry;
    u_int sleep;
    int pending;
    parameter_t *param;
    char *mem;
} process_t;

    #define MAX_FORK 100
typedef struct champion {
    u_int id;
    char name[PROG_NAME_LENGTH + 1];
    char *champ_code;
    size_t champ_code_len;
    u_int process_nb;
    process_t *process[MAX_FORK];
    size_t last_live;
    _Bool alive;
} champion_t;

typedef struct corewar {
    u_int champ_nb;
    champion_t **champions;
    size_t cycle;
    char mem[MEM_SIZE + 10];
    int dump_flag;
    size_t live_nb;
    size_t cycle_to_die;
} corewar_t;

typedef struct parsing {
    int error;
    char *champion_path[4];
    int champions_id[4];
    int champions_start[4];
    int dump_flag;
} parsing_t;

#endif
