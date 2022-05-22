/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** eleven_sixteen
*/

#include "corewar.h"
#include "my.h"
#include "op.h"
#include <stdint.h>

void sti(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    uint8_t arg_index[4] = {0};
    sti_arg_pars(arg_type, arg_index);
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_index, mem, pc);
    int res = 0;
    for (int i = 1; i <= 2; i++) {
        if (arg_type[i] == T_REG)
            res += champion->reg[arg[i]];
        if (arg_type[i] == T_DIR)
            res += arg[i];
        if (arg_type[i] == T_IND) {
            int end = mem[*pc + arg[i]];
            my_revint(&end, 2);
            res += end;
        }
    }
    mem[*pc + res] = champion->reg[arg[0]];
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void lld(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    if (arg_type[0] == T_IND)
        champion->reg[arg[1]] = read_mem(*pc + arg[0] % IDX_MOD, 1, mem);
    else if (arg_type[0] == T_DIR)
        champion->reg[arg[1]] = arg[0];
    if (arg[0] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void lldi(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int arg_index[] = {4, 4, 1, 0};
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_index, mem, pc);
    int res = 0;
    for (int i = 0; i < 2; i++) {
        if (arg_type[i] == T_REG)
            res += champion->reg[arg[i]];
        if (arg_type[i] == T_DIR)
            res += arg[i];
        if (arg_type[i] == T_IND) {
            int end = mem[*pc + arg[i]];
            my_revint(&end, 2);
            res += end;
        }
    }
    *pc = (*pc + res) % MEM_SIZE;
    if (*pc < 0)
        pc += MEM_SIZE;
    free(arg_type);
}

void aff(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    write(1, &arg[0], 1);
    *pc = (*pc + cpt) % MEM_SIZE;
}

void lfork(int *pc, champion_t *champion, uint8_t *mem)
{
    *pc = (*pc + 3) % MEM_SIZE;
}
