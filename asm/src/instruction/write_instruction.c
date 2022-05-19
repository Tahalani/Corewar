/*
** EPITECH PROJECT, 2022
** instruct
** File description:
** write_instruction
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_live(int fd, count_t *count_sruct)
{
    char c = 1;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_ld(int fd, count_t *count_sruct)
{
    char c = 2;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_st(int fd, count_t *count_sruct)
{
    char c = 3;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_add(int fd, count_t *count_sruct)
{
    char c = 4;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_sub(int fd, count_t *count_sruct)
{
    char c = 5;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}
