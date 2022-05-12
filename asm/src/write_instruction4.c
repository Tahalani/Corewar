/*
** EPITECH PROJECT, 2022
** azerty
** File description:
** azerty
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_aff(int fd)
{
    char c = 10;

    write(fd, &c, 1);
    return (0);
}
