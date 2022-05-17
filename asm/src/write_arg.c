/*
** EPITECH PROJECT, 2022
** arg
** File description:
** arg
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int conv_2_10(char *num)
{
    int res = 0;
    int cpt = 0;

    for (int i = 7; i > -1; i--) {
        res += (num[i] - '0') * my_compute_power_rec(2, cpt);
        cpt++;
    }
    return res;
}

int write_bite(int bit, int fd)
{
    static int cpt = 0;
    static char buffer[8];
    unsigned char character = 0;

    if (bit > 9 || bit < 0)
        return 84;
    buffer[cpt] = bit + '0';
    if (cpt == 7) {
        cpt = 0;
        character = (unsigned char)conv_2_10(buffer);
        write(fd, &character, 1);
        return cpt;
    } else
        cpt++;
    return cpt;
}

int write_total_arg(int fd, char **array_line)
{
    char *value_arg = malloc(sizeof(char) * (8 + 1));
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
    for (int i = 0; i != 8; i++) {
        int nb_char = my_get_char_nbr(value_arg[i]);
        write_bite(nb_char, fd);
    }
    return (0);
}

int write_arg(int fd, char *array_line)
{
    for (unsigned int i = 0; array_line[i] != '\0'; i++) {
        if (array_line[i] == 'r')
            write_register(fd, ATOD(array_line[i + 1]));
        if (array_line[i] == DIRECT_CHAR && array_line[i + 1] != LABEL_CHAR)
            write_modulo(fd, ATOD(array_line[i + 1]));
    }
    return (0);
}