/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "my.h"
#include "corewar.h"

int compare_nbr_prog_value(champion_t *champion, corewar_t *corewar,
int cpt_player)
{
    for (int j = 0; j < corewar->nbr_champ; j++) {
        if (champion[j].prog_nbr == cpt_player)
            return 84;
    }
    return 0;
}

void verif_if_number_already_exist(champion_t *champion, int *i,
corewar_t *corewar, int *cpt_player)
{
    if (champion[*i].prog_nbr == 0) {
        if (compare_nbr_prog_value(champion, corewar, *cpt_player) == 84) {
            *cpt_player += 1;
            *i = 0;
        } else {
            champion[*i].prog_nbr = *cpt_player;
            *cpt_player += 1;
        }
    }
}

int compare_same_value(champion_t *champion, corewar_t *corewar, int nbr)
{
    int cpt = 0;

    for (int j = 0; j < corewar->nbr_champ; j++) {
        if (champion[j].prog_nbr == nbr || champion[j].prog_nbr < 0)
            cpt++;
    }
    return (cpt == 1) ? 0 : 84;
}

int set_random_number_adress(corewar_t *corewar, champion_t *champion)
{
    int cpt_player = 1;

    for (int i = 0; i < corewar->nbr_champ; i++) {
        if (champion[i].is_valid == -1)
            return 84;
        if (champion[i].prog_nbr != 0 &&
        compare_same_value(champion, corewar, champion[i].prog_nbr) == 84)
            return 84;
        verif_if_number_already_exist(champion, &i, corewar, &cpt_player);
    }
    return 0;
}