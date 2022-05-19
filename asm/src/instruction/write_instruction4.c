/*
** EPITECH PROJECT, 2022
** azerty
** File description:
** azerty
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_aff(int fd, count_t *count_sruct)
{
    char c = 16;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_register(int fd, int post_register, count_t *count_sruct)
{
    char c = post_register;

    count_sruct->byte++;
    write(fd, &c, 1);
    return (0);
}

int write_modulo(int fd, int post_modulo, char *mnemonic, count_t *count_sruct)
{
    int arg = post_modulo;

    for (unsigned int i = 0; i != 16; i++) {
        if (strstr(mnemonic, ARG[i].mnemonic) != NULL) {
            count_sruct->byte += ARG[i].byte;
            write(fd, &arg, ARG[i].byte);
            return (0);
        }
    }
    return (0);
}
