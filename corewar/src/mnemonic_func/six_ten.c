/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** six_ten
*/

#include "corewar.h"
#include "my.h"
#include "op.h"
#include <stdint.h>

void and(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int res = 0;
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    res = champion->reg[arg[0]] & champion->reg[arg[1]];
    champion->reg[arg[2]] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void or(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int res = 0;
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    res = champion->reg[arg[0]] | champion->reg[arg[1]];
    champion->reg[arg[2]] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void xor(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int res = 0;
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    res = champion->reg[arg[0]] ^ champion->reg[arg[1]];
    champion->reg[arg[2]] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void zjmp(int *pc, champion_t *champion, uint8_t *mem)
{
    int index = read_mem(*pc + 1, 2, mem);
    my_revint(&index, 2);
    *pc = (*pc + index) % MEM_SIZE;
    while (*pc < 0)
        *pc += MEM_SIZE;
}

void ldi(int *pc, champion_t *champion, uint8_t *mem)
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
    *pc = (*pc + res % IDX_MOD) % MEM_SIZE;
    if (*pc < 0)
        pc += MEM_SIZE;
    free(arg_type);
}