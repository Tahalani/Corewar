/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** mem_func
*/

#include "corewar.h"
#include "my.h"
#include "op.h"

static void my_put_hex(long long unsigned int nb)
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
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 48 == 0 && i != 0)
            write(1, "\n", 1);
        if (mem[i] < 16)
            write(1, "0", 1);
        my_put_hex(mem[i]);
        write(1, " ", 1);
    }
}

uint8_t *mem_alloc(void)
{
    uint8_t *mem = malloc(MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    return mem;
    show_mem(mem);
}

int insert_mem(uint8_t *mem, champion_t *champion)
{
    int size_total_champ = champion[0].header.prog_size +
    champion[1].header.prog_size;

    if (size_total_champ >= MEM_SIZE)
        return 84;
    verif_adress(mem, champion);
    if (insert_champ(mem, champion) == 84)
        return 84;
    return 0;
}

void free_struct(corewar_t corewar, champion_t *champion)
{
    for (int i = 0; i < corewar.nbr_champ; i++){
        free(champion[i].file_name);
    }
    free(champion);
}