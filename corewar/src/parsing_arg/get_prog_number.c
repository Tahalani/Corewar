/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "my.h"
#include "corewar.h"

int get_prog_nbr(champion_t *champion, int ac, char **av, int i)
{
    if (i - 1 > 0 && my_strcmp("-n", av[i - 1]) == 0)
        return 84;
    if (i - 2 > 0 && my_strcmp("-n", av[i - 2]) == 0) {
        if (my_str_isnum(av[i - 1]) == 1) {
            champion->prog_nbr = my_getnbr(av[i - 1]);
        } else
            return 84;
    }
    if (i - 4 > 0 && my_strcmp("-n", av[i - 4]) == 0) {
        if (my_str_isnum(av[i - 3]) == 1) {
            champion->prog_nbr = my_getnbr(av[i - 3]);
        } else
            return 84;
    }
    champion->reg[1] = champion->prog_nbr;
    return 0;
}