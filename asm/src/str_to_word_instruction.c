/*
** EPITECH PROJECT, 2022
** instruction
** File description:
** instruction
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int verif_char_instruction(char x, char separator)
{
    if (x == separator || x == '\n' || x == ':')
        return 0;
    return 1;
}

int count_word_instruction(char const *str, char separator)
{
    int i = 0;
    int count = 1;

    for (; str[i] != '\0'; i++) {
        if (verif_char_instruction(str[i], separator) == 1 &&
        verif_char_instruction(str[i + 1],
            separator) == 0)
            count++;
    }
    return (count);
}

int size_word_instruction(char const *str, int i, char separator)
{
    int count = 0;

    for (; str[i] != separator && str[i] != '\0' &&
    str[i] != ':' && str[i] != '\n'; i++)
        count++;
    return (count);
}

char **str_to_word_instruction(char const *str, char separator)
{
    char **tab = NULL;
    int i = 0;
    int size = 0;
    int count = count_word_instruction(str, separator);

    tab = malloc(sizeof(char *) * (count + 1));
    tab[count] = NULL;
    for (int y = 0; y != count; y++) {
        for (; str[i] == separator; i++);
        size = size_word_instruction(str, i, separator);
        tab[y] = malloc(sizeof(char) * (size + 1));
        tab[y][size] = '\0';
        for (int x = 0; x != size; x++) {
            tab[y][x] = str[i];
            i++;
        }
        i++;
    }
    return (tab);
}
