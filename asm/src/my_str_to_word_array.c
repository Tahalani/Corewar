/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my str to word
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

void count_nbr_word(char const *str, int *nb_mot)
{
    while (str[0] == '\n')
        str++;
    while (str[0] != '\0') {
        while (str[0] != ' ' && str[0] != '\0' && str[0] != '\t')
            str++;
        while (str[0] == ' ')
            str++;
        *nb_mot += 1;
        if (str[0] == '\0') {
            break;
        }
    }
}

int malloc_nbr_word(char const *str, char **dest, int nb_mot)
{
    int i = 0;
    int c = 0;

    while (i < nb_mot) {
        int length_m = 0;
        while ((str[c] == ' ') && str[c] != '\0' && str[0] != '\t') {
            c++;
        }
        while (str[c] != '\0' && str[c] != ' ' && str[0] != '\t') {
            length_m++;
            c++;
        }
        dest[i] = malloc(sizeof(char) * (length_m + 1));
        dest[i][length_m] = '\0';
        if (dest[i] == NULL)
            return 84;
        i++;
    }
    return 0;
}

void put_in_char(char const *str, char **dest, int nb_mot)
{
    int c = 0;
    int i = 0;

    while (i < nb_mot) {
        int length_m = 0;
        while ((str[c] == ' ') && str[c] != '\0' && str[0] != '\t') {
            c++;
        }
        while (str[c] != '\0' && str[c] != ' ' && str[0] != '\t') {
            dest[i][length_m] = str[c];
            length_m++;
            c++;
        }
        i++;
    }
}

char **my_str_to_word_array(char const *str)
{
    int nb_mot = 0;
    char **dest;

    count_nbr_word(str, &nb_mot);
    dest = malloc(sizeof(char *) * (nb_mot + 1));
    if (dest == NULL)
        return NULL;
    dest[nb_mot] = NULL;
    if (malloc_nbr_word(str, dest, nb_mot) == 84)
        return NULL;
    put_in_char(str, dest, nb_mot);
    return dest;
}