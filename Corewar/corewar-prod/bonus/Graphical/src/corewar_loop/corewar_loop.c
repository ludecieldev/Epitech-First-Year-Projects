/*
** EPITECH PROJECT, 2024
** B_CPE_200_LIL_2_1_corewar_alexandre_garbe
** File description:
** corewar_loop.c
*/

#include "corewar.h"
#include "instruction_tab.h"
#include "corewar_loop.h"
#include "memory_meta.h"

static void kill_dead_player(corewar_t *corewar, champion_t *champ)
{
    if (corewar->cycle - champ->last_live > corewar->cycle_to_die)
        champ->alive = 0;
}

static void run_instruction(corewar_t *corewar, champion_t *champ)
{
    if (champ->alive == 0)
        return;
    for (u_int i = 0; i < champ->process_nb; i++) {
        if (champ->process[i]->pending && champ->process[i]->sleep == 0) {
            instructions[champ->process[i]->pending](corewar,
                champ->process[i]->param, champ, champ->process[i]);
            champ->process[i]->pending = 0;
        }
    }
}

static void load_param(process_t *process)
{
    process->param->param_info = *((u_char *)get_address(process->mem,
        process->pc));
    process->pc++;
    for (int i = 0; i < (int)op_tab[process->param->instr - 1].nbr_args; i++) {
        process->param->param[i] = 0;
        my_strncpy_dumb((char *)&(process->param->param[i]),
            get_address(process->mem, process->pc), PARAM_SIZE(get_param_type(
            process->param->param_info, i + 1, process->param->instr)));
        process->pc += PARAM_SIZE(get_param_type(process->param->param_info, i
            + 1, process->param->instr));
    }
}

static void load_instruction(process_t *process)
{
    char *mem = get_address(process->mem, process->pc);

    process->param->pc = get_address(process->mem, process->pc);
    if (mem < process->mem || *mem <= 0 || *mem > 16) {
        process->pc++;
        return;
    }
    process->param->instr = (int)(mem[0]);
    process->pc++;
    process->sleep += op_tab[process->param->instr - 1].nbr_cycles - 1;
    process->pending = process->param->instr;
    if (!(HAS_SPEC(process->param->instr))) {
        process->param->param[0] = 0;
        my_strncpy_dumb((char *)&(process->param->param[0]),
            get_address(process->mem, process->pc),
            SIZE_DIR(process->param->instr));
        process->pc += SIZE_DIR(process->param->instr);
        return;
    }
    load_param(process);
}

static void update_champ(champion_t *champ)
{
    if (champ->alive == 0)
        return;
    for (u_int i = 0; i < champ->process_nb; i++) {
        if (champ->process[i]->sleep > 0)
            champ->process[i]->sleep--;
        if (champ->process[i]->pending != 0)
            continue;
        load_instruction(champ->process[i]);
    }
}

static void display_winner(long max_champ, char *max_champ_name)
{
    write(1, "The player ", 11);
    my_putnbr((long)max_champ);
    write(1, "(", 1);
    write(1, max_champ_name, my_strlen(max_champ_name));
    write(1, ")has won.\n", 10);
}

void corewar_loop(corewar_t *corewar, memory_meta_t *meta)
{
    size_t max = 0;
    size_t max_champ = 0;
    WINDOW *win = newwin(35, 70, 1, 1);
    while (!is_win(corewar) && corewar->cycle != (size_t)corewar->dump_flag) {
        for (u_int i = 0; i < corewar->champ_nb; i++) {
            kill_dead_player(corewar, corewar->champions[i]);
            run_instruction(corewar, corewar->champions[i]);
            update_champ(corewar->champions[i]);
        }
        corewar->cycle++;
        dump_mem(win, corewar->mem, meta);
        napms(100);
    }
    for (size_t i = 0; i < corewar->champ_nb; i++) {
        if (corewar->champions[i]->last_live > max) {
            max = corewar->champions[i]->last_live;
            max_champ = corewar->champions[i]->id;
        }
    }
    display_winner((long)max_champ, corewar->champions[max_champ]->name);
    delwin(win);
}

