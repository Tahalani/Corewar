/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "my.h"
#include "corewar.h"

int get_champ_adress(champion_t *champion, char **av, int i)
{
    if (i - 1 > 0 && my_strcmp("-a", av[i - 1]) == 0)
        return 84;
    if (i - 2 > 0 && my_strcmp("-a", av[i - 2]) == 0 &&
    my_str_isnum(av[i - 1]) == 1)
        champion->adress = my_getnbr(av[i - 1]);
    return 0;
}

void struct_init(champion_t *champion)
{
    for (int i = 0; i < REG_NUMBER; i++)
        champion->reg[i] = 0;
    champion->carry = 0;
    champion->prog_nbr = 0;
    champion->living = 0;
    champion->waiting = 0;
    champion->adress = -1;
    champion->is_valid = -1;
}