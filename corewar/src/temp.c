/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include <stdlib.h>
#include "op.h"
#include <unistd.h>
#include <stdint.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_hex(long long unsigned int nb)
{
    if (nb / 16 != 0)
        my_put_hex(nb / 16);
    if (nb % 16 > 9)
        my_putchar((nb % 16) + 55);
    if (nb % 16 < 10)
        my_putchar((nb % 16) + '0');
}

void show_mem(uint8_t *mem)
{
    for (int i = 0; i < 48; i++) {
        if (i < 16)
            write(1, "0", 1);
        my_put_hex(i);
        write(1, " ", 1);
    }
    write(1, "\n", 1);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 48 == 0 && i != 0)
            write(1, "\n", 1);
        if (mem[i] < 16)
            write(1, "0", 1);
        my_put_hex(mem[i]);
        write(1, " ", 1);
    }
}

int main(void)
{
    uint8_t *mem = malloc(MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    show_mem(mem);
}

