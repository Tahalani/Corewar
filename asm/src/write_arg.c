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

int write_bite(int bit, int fd, count_t *count_sruct)
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
        count_sruct->byte++;
        return cpt;
    } else
        cpt++;
    return cpt;
}

int write_total_arg(int fd, char **array_line, count_t *count_sruct)
{
    char *value_arg = malloc(sizeof(char) * (8 + 1));
    unsigned int k = 0;

    value_arg[0] = '\0';
    for (unsigned int i = 1; array_line[i] != NULL; i++, k++) {
        if (array_line[i][0] == 'r')
            value_arg = my_strcat(value_arg, "01");
        else
            value_arg = my_strcat(value_arg, "10");
    }
    for (unsigned int i = my_strlen(value_arg); i != 8; i++)
        value_arg[i] = '0';
    for (int i = 0; i != 8; i++) {
        int nb_char = my_get_char_nbr(value_arg[i]);
        write_bite(nb_char, fd, count_sruct);
    }
    return (0);
}

int get_pos_label(int fd, count_t *count_sruct, char *array_line, int line)
{
    int c = -1;
    char *line_str = NULL;
    char *byte = NULL;

    count_sruct->get_label[count_sruct->count_distance] = array_line;
    line_str = int_to_str(line);
    byte = int_to_str(count_sruct->byte);
    if (line_str[0] == '\0')
        line_str[0] = '0';
    if (byte[0] == '\0')
        byte[0] = '0';
    count_sruct->get_label[count_sruct->count_distance + 1] = line_str;
    count_sruct->get_label[count_sruct->count_distance + 2] = byte;
    count_sruct->count_distance += 3;
    count_sruct->byte += 2;
    write(fd, &c, 2);
    return (0);
}

int write_arg(int fd, char *array_line, char *mnemonic, count_t *co, int line)
{
    int return_val = 0;

    for (unsigned int i = 0; array_line[i] != '\0'; i++) {
        if (array_line[i] == 'r')
            return_val = write_register(fd, array_line, co);
        if (return_val == 84)
            return (84);
        if (array_line[i] == DIRECT_CHAR && array_line[i + 1] != LABEL_CHAR)
            write_modulo(fd, array_line, mnemonic, co);
        if (array_line[i] == DIRECT_CHAR && array_line[i + 1] == LABEL_CHAR)
            get_pos_label(fd, co, &array_line[3], line);
    }
    return (0);
}
