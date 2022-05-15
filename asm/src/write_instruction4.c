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
    char c = 16;

    write(fd, &c, 1);
    return (0);
}

int write_register(int fd)
{
    char c = 1;

    write(fd, &c, 1);
    return (0);
}
