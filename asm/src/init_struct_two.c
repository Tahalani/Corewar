/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** init_struct_two
*/

#include "my.h"
#include "corewar.h"
#include "op.h"
#include <stdint.h>

char *init_struct_count(count_t *count_sruct, char *name_file, char **av)
{
    count_sruct->count_label = 0;
    count_sruct->count_distance = 0;
    count_sruct->label_array = malloc(sizeof(char *) * 500);
    count_sruct->get_label = malloc(sizeof(char *) * 500);
    name_file[my_strlen(av[1]) - 2] = '\0';
    for (int i = 0; av[1][i] != '.' && av[1][i] != '\0'; i++)
        name_file[i] = av[1][i];
    name_file = my_strcat(name_file, ".lol\0");
    return (name_file);
}

int check_champ_info(header_t *header, int count, char **array)
{
    if (count == 0) {
        memset(header->prog_name, 0, PROG_NAME_LENGTH);
        my_strcpy(header->prog_name, array[1]);
    }
    if (count == 1) {
        memset(header->comment, 0, COMMENT_LENGTH);
        my_strcpy(header->comment, array[1]);
        return (1);
    }
    return (84);
}

int write_finally_prog_size(header_t *header, count_t *count_sruct, int fd)
{
    off_t progsize_pos;

    header->prog_size = count_sruct->byte;
    progsize_pos = lseek(fd, offsetof(header_t, prog_size), SEEK_SET);
    my_rev_bit((uint8_t*)&header->prog_size, 4);
    write(fd, &header->prog_size, progsize_pos);
    return (0);
}

uint8_t *my_rev_bit(uint8_t *str, unsigned int len)
{
    uint8_t c;

    for (unsigned int i = 0; i < len; i++, len--) {
        c = str[i];
        str[i] = str[len - 1];
        str[len - 1] = c;
    }
    return (str);
}
