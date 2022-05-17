/*
** EPITECH PROJECT, 2022
** instruct
** File description:
** write_instruction
*/

#include "my.h"
#include "corewar.h"

int write_live(int fd)
{
    char c = 1;

    write(fd, &c, 1);
    return (0);
}

int write_ld(int fd)
{
    char c = 2;

    write(fd, &c, 1);
    return (0);
}

int write_st(int fd)
{
    char c = 3;

    write(fd, &c, 1);
    return (0);
}

int write_add(int fd)
{
    char c = 4;

    write(fd, &c, 1);
    return (0);
}

int write_sub(int fd)
{
    char c = 5;

    write(fd, &c, 1);
    return (0);
}
