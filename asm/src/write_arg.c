/*
** EPITECH PROJECT, 2022
** arg
** File description:
** arg
*/

#include "my.h"
#include "corewar.h"
#include "option_asm.h"
#include "op.h"

int write_arg(int fd, char **array_line)
{
    char *value_arg = malloc(sizeof(int) * (8 + 1));
    unsigned int k = 0;

    value_arg[0] = '\0';
    for (unsigned int i = 1; array_line[i] != NULL; i++) {
        if (array_line[i][0] == 'r')
            strcat(value_arg, "01");
        else
            strcat(value_arg, "10");
        k++;
    }
    for (unsigned int i = strlen(value_arg); i != 8; i++)
       value_arg[i] = '0';
    // write(fd, &value_arg, 1);
    return (0);
}
