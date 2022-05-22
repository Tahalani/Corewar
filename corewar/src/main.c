/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "corewar.h"
#include "my.h"
#include "op.h"
#include <stdint.h>

void (*mne[16])(int *, champion_t *, uint8_t *) = {live, ld, st,
add, sub, and, or, xor, zjmp, ldi, sti, lfork, lld, lldi, lfork, aff};

int check_live(champion_t *champion, corewar_t corewar)
{
    int living = 0;
    for (int i = 0; i < corewar.nbr_champ; i++) {
        if (champion[i].living == 1) {
            champion[i].living = 0;
            living += 1;
        } else {
            champion[i].living = -1;
        }
    }
    return living;
}

void print_winner(corewar_t corewar, champion_t *champion)
{
    my_putchar('\n');
    for (int i = 0; i < corewar.nbr_champ; i++)
        if (champion[i].living != -1) {
            my_putstr("The player ");
            my_put_nbr(champion[i].prog_nbr);
            my_putchar('(');
            my_putstr(champion[i].header.prog_name);
            my_putstr(")has won.\n");
        }
}

void get_time(champion_t *champion, corewar_t corewar, uint8_t *mem)
{
    if (champion[0].waiting == 0 && champion[0].pc > 0 &&
    champion[0].pc < MEM_SIZE)
        if (mem[champion[0].pc] < 17 && mem[champion[0].pc] > 0)
            champion[0].waiting = op_tab[mem[champion[0].pc] - 1].nbr_cycles;
    if (champion[1].waiting == 0 && champion[1].pc > 0 &&
    champion[1].pc < MEM_SIZE)
        if (mem[champion[1].pc] < 17 && mem[champion[1].pc] > 0)
            champion[1].waiting = op_tab[mem[champion[1].pc] - 1].nbr_cycles;
    if (champion[0].waiting > 0)
        champion[0].waiting -= 1;
    if (champion[1].waiting > 0)
        champion[1].waiting -= 1;
}

void warloop(corewar_t corewar, champion_t *chp, uint8_t *mem)
{
    int cycle = 0;
    int cycle_to_die = CYCLE_TO_DIE;
    int living = 2;
    while (living > 1 && cycle_to_die > 0) {
        get_time(chp, corewar, mem);
        if (chp[0].pc >= 0 && chp[0].pc < MEM_SIZE && mem[chp[0].pc]< 17 &&
        mem[chp[0].pc] > 0 && chp[0].waiting == 0)
            mne[mem[chp[0].pc] - 1](&chp[0].pc, &chp[0], mem);
        if (chp[1].pc >= 0 && chp[1].pc < MEM_SIZE && mem[chp[1].pc]< 17 &&
        mem[chp[1].pc] > 0 && chp[1].waiting == 0)
            mne[mem[chp[1].pc] - 1](&chp[1].pc, &chp[1], mem);
        if (cycle % cycle_to_die == 0 && cycle != 0) {
            living = check_live(chp, corewar);
            cycle_to_die -= CYCLE_DELTA;
        }
        cycle++;
    }
}

int main(int ac, char **av)
{
    corewar_t corewar;
    champion_t *champion;
    uint8_t *mem = mem_alloc();

    if (ac == 1)
        return 84;
    champion = parsing_argument(ac, av, &corewar);
    if (champion == NULL)
        return 84;
    if (insert_mem(mem, champion) == 84)
        return 84;
    for (int i = 0; i < corewar.nbr_champ; i++)
        champion[i].pc = champion[i].adress;
    warloop(corewar, champion, mem);
    show_mem(mem);
    print_winner(corewar, champion);
    free_struct(corewar, champion);
    return 0;
}