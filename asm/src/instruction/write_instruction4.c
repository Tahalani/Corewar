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

int write_register(int fd, char *post_register, count_t *count_sruct)
{
    char *after = malloc(sizeof(char) * 4);
    int result = 0;
    int j = 0;

    for (int i = 1; post_register[i] != '\0'; i++) {
        after[j] = post_register[i];
        j++;
    }
    result = my_getnbr(after);
    count_sruct->byte++;
    printf("ici = %s\n", after);
    if (result >= 1 && result <= REG_NUMBER)
        write(fd, &result, 1);
    else
        return (84);
    return (0);
}

int write_modulo(int fd, char *post_modulo, char *mnemonic, count_t *count_sruct)
{
    int arg = 0;
    char *after = malloc(sizeof(char) * 4);
    int j = 0;

    for (int i = 1; post_modulo[i] != '\0'; i++) {
        after[j] = post_modulo[i];
        j++;
    }
    arg = my_getnbr(after);
    for (unsigned int i = 0; i != 16; i++) {
        if (strstr(mnemonic, ARG[i].mnemonic) != NULL) {
            count_sruct->byte += ARG[i].byte;
            my_rev_bit((void *)&arg, ARG[i].byte);
            write(fd, &arg, ARG[i].byte);
            return (0);
        }
    }
    return (0);
}
