/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "corewar.h"

void free_struct(corewar_t corewar, champion_t *champion)
{
    for (int i = 0; i < corewar.nbr_champ; i++){
        free(champion[i].file_name);
    }
    free(champion);
}

int main(int ac, char **av)
{
    corewar_t corewar;
    champion_t *champion;
    if (ac == 1)
        return 84;
    champion = parsing_argument(ac, av, &corewar);
    if (champion == NULL) {
        return 84;
    }
    free_struct(corewar, champion);
    return 0;
}