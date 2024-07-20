/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** get_champ_code.c
*/

#include "corewar.h"

static corewar_t *init_corewar(parsing_t *parse)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));
    int champ_nb = 0;

    for (; champ_nb < 4 && parse->champion_path[champ_nb]; champ_nb++);
    corewar->champ_nb = champ_nb;
    corewar->champions = malloc(sizeof(champion_t *) * (champ_nb + 1));
    corewar->cycle = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->live_nb = 0;
    for (int i = 0; i < MEM_SIZE + 10; i++)
        corewar->mem[i] = 0;
    return corewar;
}

process_t *init_process(int id, void *mem_index, corewar_t *corewar)
{
    process_t *process = malloc(sizeof(process_t));

    process->carry = 0;
    process->pc = mem_index;
    for (int i = 0; i < REG_NUMBER; i++) {
        process->reg[i] = 0;
    }
    process->reg[0] = id;
    process->sleep = 0;
    process->pending = 0;
    process->param = malloc(sizeof(parameter_t));
    process->param->param_info = 0;
    process->param->param[0] = 0;
    process->param->param[1] = 0;
    process->param->param[2] = 0;
    process->param->pc = process->pc;
    process->param->instr = 0;
    process->mem = corewar->mem;
    return process;
}

static champion_t *init_champ(void)
{
    champion_t *champ = malloc(sizeof(champion_t));

    champ->alive = 1;
    champ->last_live = 0;
    champ->process_nb = 1;
    for (int i = 0; i < MAX_FORK; i++)
        champ->process[i] = 0;
    return champ;
}

static champion_t *get_champ(char *path, int id, void *mem_index,
    corewar_t *corewar)
{
    champion_t *champ = init_champ();
    int fd = open(path, O_RDONLY);
    header_t *header = malloc(sizeof(header_t));
    char buffer[MEM_SIZE + 1];

    if (fd == -1)
        return NULL;
    read(fd, header, sizeof(header_t));
    my_strncpy(champ->name, header->prog_name, PROG_NAME_LENGTH + 1);
    free(header);
    champ->id = id;
    champ->process[0] = init_process((int)champ->id, mem_index, corewar);
    champ->champ_code_len = read(fd, buffer, MEM_SIZE);
    champ->champ_code = malloc(champ->champ_code_len + 1);
    for (size_t i = 0; i < champ->champ_code_len; i++)
        champ->champ_code[i] = buffer[i];
    close(fd);
    return champ;
}

corewar_t *setup_corewar(parsing_t *parse)
{
    corewar_t *corewar = init_corewar(parse);
    u_int mem_index = 0;

    for (u_int i = 0; i < corewar->champ_nb; i++) {
        corewar->champions[i] = get_champ(parse->champion_path[i], (int)i,
            corewar->mem + mem_index, corewar);
        if (corewar->champions[i] == NULL)
            return NULL;
        for (size_t j = 0; j < corewar->champions[i]->champ_code_len; j++)
            *(corewar->mem + mem_index + j) =
                corewar->champions[i]->champ_code[j];
        corewar->champions[i]->process[0]->pc = (corewar->mem + mem_index);
        mem_index += (u_int)((1.f / (float)corewar->champ_nb) * MEM_SIZE);
    }
    corewar->dump_flag = parse->dump_flag;
    return corewar;
}
