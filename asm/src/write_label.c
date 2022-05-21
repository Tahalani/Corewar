/*
** EPITECH PROJECT, 2022
** sdfgb
** File description:
** sdfgbn
*/

#include "my.h"
#include "corewar.h"
#include "option_asm.h"
#include "op.h"

int write_label(int fd, count_t *count_sruct)
{
    int label_byte = 0;
    int line_byte = 0;
    int check = 0;
    int final_label = 0;

    count_sruct->label_array[count_sruct->count_label] = NULL;
    count_sruct->get_label[count_sruct->count_distance] = NULL;
    for (unsigned int i = 0; count_sruct->get_label[i + 1] != NULL; i += 2) {
        for (unsigned int k = 0; count_sruct->label_array[k] != NULL; k++) {
            if (my_getnbr(count_sruct->get_label[i + 1]) ==
            my_getnbr(count_sruct->label_array[k]) && check == 0) {
                line_byte = my_getnbr(count_sruct->label_array[k + 1]);
                check = 1;
            }
            if (strstr(count_sruct->label_array[k], count_sruct->get_label[i]) != NULL) {
                label_byte = my_getnbr(count_sruct->label_array[k + 2]);
            }
        }
        final_label = label_byte - line_byte;
        printf("%d\n", final_label);
        check = 0;
    }
    return(0);
}
