/*
** EPITECH PROJECT, 2022
** sdfgb
** File description:
** sdfgbn
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int write_label(int fd, count_t *count_sruct, header_t *header)
{
    int label_byte = 0;
    int line_byte = 0;
    int check = 0;
    int final_label = 0;
    off_t pos;

    count_sruct->label_array[count_sruct->count_label] = NULL;
    count_sruct->get_label[count_sruct->count_distance] = NULL;
    for (unsigned int i = 0; count_sruct->get_label[i + 1] != NULL; i += 3) {
        for (unsigned int k = 0; count_sruct->label_array[k] != NULL; k++) {
            if (my_getnbr(count_sruct->get_label[i + 1]) ==
            my_getnbr(count_sruct->label_array[k]) && check == 0) {
                line_byte = my_getnbr(count_sruct->label_array[k + 1]);
                check = 1;
            }
            if (my_strstr(count_sruct->label_array[k],
            count_sruct->get_label[i]) != NULL) {
                label_byte = my_getnbr(count_sruct->label_array[k + 2]);
            }
        }
        lseek(fd, sizeof(header_t) + atoi(count_sruct->get_label[i + 2]), SEEK_SET);
        final_label = label_byte - line_byte;
        my_rev_bit((uint8_t*)&final_label, 2);
        write(fd, &final_label, sizeof(short));
        check = 0;
    }
    return(0);
}
