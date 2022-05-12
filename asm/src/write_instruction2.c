/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-taha.alani
** File description:
** write_instruction2
*/

#include "my.h"
#include "corewar.h"

int write_and(int fd)
{
    char c = 6;

    write(fd, &c, 1);
    return (0);
}

int write_or(int fd)
{
    char c = 7;

    write(fd, &c, 1);
    return (0);
}

int write_xor(int fd)
{
    char c = 8;

    write(fd, &c, 1);
    return (0);
}

int write_zjmp(int fd)
{
    char c = 9;

    write(fd, &c, 1);
    return (0);
}

int write_ldi(int fd)
{
    char c = 'a';

    write(fd, &c, 1);
    return (0);
}
