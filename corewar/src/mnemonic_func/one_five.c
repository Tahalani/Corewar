/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** mnemonic 1 to 5
*/

#include "corewar.h"
#include "my.h"
#include "op.h"
#include <stdint.h>

void live(int *pc, champion_t *champion, uint8_t *mem)
{
    my_putstr("The player ");
    my_put_nbr(champion->prog_nbr);
    my_putchar('(');
    my_putstr(champion->header.prog_name);
    my_putstr(")is alive.\n");
    if (champion->living != -1)
        champion->living = 1;
    *pc = (*pc + 5) % MEM_SIZE;
}

void ld(int *pc, champion_t *champion, uint8_t *mem)
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

void st(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    if (arg_type[1] == T_REG)
        champion->reg[arg[1]] = champion->reg[arg[0]];
    else if (arg_type[1] == T_IND)
        mem[*pc + arg[1] % IDX_MOD] = champion->reg[arg[0]];
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void add(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int res = 0;
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    res = champion->reg[arg[0]] + champion->reg[arg[1]];
    champion->reg[arg[2]] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}

void sub(int *pc, champion_t *champion, uint8_t *mem)
{
    uint8_t *arg_type = read_bytecode(mem[*pc + 1]);
    int res = 0;
    int arg[4] = {0};
    int cpt = fill_arg(arg, arg_type, mem, pc);
    res = champion->reg[arg[0]] - champion->reg[arg[1]];
    champion->reg[arg[2]] = res;
    if (res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    *pc = (*pc + cpt) % MEM_SIZE;
    free(arg_type);
}