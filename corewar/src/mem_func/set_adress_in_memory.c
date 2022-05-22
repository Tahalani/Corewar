/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** mem_func
*/

#include "corewar.h"
#include "my.h"
#include "op.h"

void put_at_start(uint8_t *mem, champion_t *champion)
{
    for (int i = 0; i < champion->header.prog_size; i++)
        mem[i] = champion->buf_cmd[i];
}

void verif_adress(uint8_t *mem, champion_t *champion)
{
    for (int i = 0; i < 2; i++) {
        if (champion[i].adress == -1) {
            put_at_start(mem, &champion[i]);
            champion[i].adress = 0;
            break;
        }
    }
}

int calc_distance_champ(champion_t *champion, int prog_size_start,
int prog_size_put, uint8_t *mem)
{
    int val_start = 0;

    val_start = (prog_size_start + ((MEM_SIZE - prog_size_start) / 2)
    - prog_size_put / 2);
    champion->adress = val_start;
    for (int i = 0; i < prog_size_put; i++) {
        mem[val_start + i] = champion->buf_cmd[i];
    }
    return 0;
}

int adress_are_set(uint8_t *mem, champion_t *champion)
{
    int stock = 0;
    int j = 0;
    champion[0].adress = 0;

    for (int i = 0; i < champion[0].header.prog_size; i++)
        mem[i + champion[0].adress] = champion[0].buf_cmd[i];
    stock = champion[1].adress;
    for (int i = champion[1].adress; i < stock +
    champion[1].header.prog_size; i++, j++) {
        if (mem[i] == 0)
            mem[i] = champion[1].buf_cmd[j];
        else
            return 84;
    }
    return 0;
}

int insert_champ(uint8_t *mem, champion_t *champion)
{
    if (champion[0].adress == 0 && champion[1].adress == -1) {
        calc_distance_champ(&champion[1], champion[0].header.prog_size,
        champion[1].header.prog_size, mem);
        return 1;
    }
    if (champion[1].adress == 0 && champion[0].adress == -1) {
        calc_distance_champ(&champion[0], champion[1].header.prog_size,
        champion[0].header.prog_size, mem);
        return 1;
    }
    if (adress_are_set(mem, champion) == 84)
        return 84;
    return 0;
}