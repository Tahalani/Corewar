/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-taha.alani
** File description:
** write_instruction3
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_sti(int fd, count_t *count_sruct)
{
    char c = 11;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_fork(int fd, count_t *count_sruct)
{
    char c = 12;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_lld(int fd, count_t *count_sruct)
{
    char c = 13;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_lldi(int fd, count_t *count_sruct)
{
    char c = 14;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_lfork(int fd, count_t *count_sruct)
{
    char c = 15;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}
