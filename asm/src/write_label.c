/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write_label
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int init_count_stru(count_t *count_sruct)
{
    count_sruct->label_array[count_sruct->count_label] = NULL;
    count_sruct->get_label[count_sruct->count_distance] = NULL;
    return (0);
}

int after_label_print(count_t *count_sruct, int final_label, int fd, int i)
{
    lseek(fd, sizeof(header_t) +
    my_getnbr(count_sruct->get_label[i + 2]), SEEK_SET);
    my_rev_bit((uint8_t*)&final_label, 2);
    write(fd, &final_label, sizeof(short));
    return (i);
}

int condition_two_label(int label_byte, count_t *count_sruct, int i, int k)
{
    if (my_strstr(count_sruct->label_array[k],
    count_sruct->get_label[i]) != NULL) {
        label_byte = my_getnbr(count_sruct->label_array[k + 2]);
    }
    return (label_byte);
}

int loop_label_func(count_t *count_sruct, int i, int check)
{
    int final_label = 0;
    int label_byte = 0;
    int line_byte = 0;

    for (unsigned int k = 0; count_sruct->label_array[k] != NULL; k++) {
        if (my_getnbr(count_sruct->get_label[i + 1]) ==
        my_getnbr(count_sruct->label_array[k]) && check == 0) {
            line_byte = my_getnbr(count_sruct->label_array[k + 1]);
            check = 1;
        }
        label_byte = condition_two_label(label_byte, count_sruct, i, k);
    }
    final_label = label_byte - line_byte;
    return (final_label);
}

int write_label(int fd, count_t *count_sruct)
{
    int check = 0;
    int final_label = 0;

    init_count_stru(count_sruct);
    for (unsigned int i = 0; count_sruct->get_label[i + 1] != NULL; i += 3) {
        final_label = loop_label_func(count_sruct, i, check);
        i = after_label_print(count_sruct, final_label, fd, i);
        check = 0;
    }
    return (0);
}
