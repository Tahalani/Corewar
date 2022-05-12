/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-taha.alani
** File description:
** write_instruction3
*/

#include "my.h"
#include "corewar.h"
#include "option_asm.h"

int write_sti(int fd)
{
    char c = 11;

    write(fd, &c, 1);
    return (0);
}

int write_fork(int fd)
{
    char c = 'c';

    write(fd, &c, 1);
    return (0);
}

int write_lld(int fd)
{
    char c = 'd';

    write(fd, &c, 1);
    return (0);
}

int write_lldi(int fd)
{
    char c = 'e';

    write(fd, &c, 1);
    return (0);
}

int write_lfork(int fd)
{
    char c = 'f';

    write(fd, &c, 1);
    return (0);
}
