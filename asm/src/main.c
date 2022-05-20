/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "corewar.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (yolotron_asm(av[1], av) == -1)
        return (84);
    return (0);
}
