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
