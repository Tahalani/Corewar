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

int write_register(int fd, int post_register)
{
    char c = post_register;

    write(fd, &c, 1);
    return (0);
}

int write_modulo(int fd, int post_modulo, char *mnemonic)
{
    int arg = post_modulo;

    for (unsigned int i = 0; i != 16; i++) {
        if (strstr(mnemonic, ARG[i].mnemonic) != NULL) {
            write(fd, &arg, ARG[i].byte);
            return (0);
        }
    }
    return (0);
}
