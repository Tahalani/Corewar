/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-taha.alani
** File description:
** write_instruction2
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_and(int fd, count_t *count_sruct)
{
    char c = 6;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_or(int fd, count_t *count_sruct)
{
    char c = 7;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_xor(int fd, count_t *count_sruct)
{
    char c = 8;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_zjmp(int fd, count_t *count_sruct)
{
    char c = 9;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_ldi(int fd, count_t *count_sruct)
{
    char c = 10;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}
