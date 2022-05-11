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
    if (i - 2 > 0 && my_strcmp("-a", av[i - 2]) == 0 &&
    my_str_isalpha(av[i - 1]) == 1)
        champion->adress = my_strdup(av[i - 1]);
    return 0;
}
