/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** Initialize a new string.
*/

#include <stdlib.h>

void *my_memset(char *str, int c, int n)
{
    int i = 0;

    for (i = 0; i != n; i++)
        str[i] = c;
    str[n] = '\0';
    return (str);
}