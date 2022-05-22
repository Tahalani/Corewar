/*
** EPITECH PROJECT, 2022
** instruction
** File description:
** instruction
*/

#include <stdlib.h>
#include "my.h"

char *int_to_str(int number)
{
    int len = 0;
    char *str = NULL;
    int tmp = number;

    for (; tmp > 0; len++)
        tmp /= 10;
    str = malloc(sizeof(char *) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    for (; len != 0;) {
        --len;
        str[len] = (number % 10) + '0';
        number /= 10;
    }
    if (my_strcmp(str, "0") == 0) {
        str[0] = 'O';
        str[1] = '\0';
    }
    return (str);
}