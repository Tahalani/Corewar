/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** mem_reading
*/

#include "corewar.h"
#include "my.h"
#include "op.h"
#include <stdint.h>

uint8_t *sti_arg_pars(uint8_t *arg_type, uint8_t *arg_index)
{
    for (int i = 0; i < 3; i++)
        if (arg_type[i] == T_REG)
            arg_index[i] = 1;
        else
            arg_index[i] = T_IND;
}

uint8_t *read_bytecode(uint8_t bytecode)
{
    uint8_t *arg_type = malloc(sizeof(uint8_t) *4);
    for (int i = 0; i < 4; i++) {
        if ((bytecode & (0b11000000 >> (i * 2))) == (0b11000000 >> i * 2))
            arg_type[i] = T_IND;
        if ((bytecode & (0b11000000 >> (i * 2))) == (0b10000000 >> i * 2))
            arg_type[i] = T_DIR;
        if ((bytecode & (0b11000000 >> (i * 2))) == (0b01000000 >> i * 2))
            arg_type[i] = T_REG;
        if ((bytecode & (0b11000000 >> (i * 2))) == 0b00000000)
            arg_type[i] = 0;
    }
    return arg_type;
}

unsigned int read_mem(int index, int size, uint8_t *mem)
{
    int *value = NULL;
    value = &mem[index];
    if (size == 1)
        return (uint8_t)*value;
    if (size == 2)
        return (int16_t)*value;
    if (size == 4)
        return (int32_t)*value;
}

int fill_arg(int *arg, uint8_t *arg_type, uint8_t *mem, int *pc)
{
    int cpt_read = 0;
    for (int i = 0; i < 4; i++) {
        if (arg_type[i] == T_DIR) {
            arg[i] = read_mem(*pc + 2 + cpt_read, 4, mem);
            my_revint(&arg[i], 4);
            cpt_read += 4;
        }
        if (arg_type[i] == T_IND) {
            arg[i] = read_mem(*pc + 2 + cpt_read, 2, mem);
            my_revint(&arg[i], 2);
            cpt_read += 2;
        }
        if (arg_type[i] == T_REG) {
            arg[i] = read_mem(*pc + 2 + cpt_read, 1, mem);
            cpt_read += 1;
        }
    }
    return cpt_read + 2;
}