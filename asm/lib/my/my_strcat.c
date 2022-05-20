/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    char *result = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(src)) + 1);
    int i = 0;

    if (result == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (int count = 0; src[count] != '\0'; count++)
        result[i + count] = src[count];
    result[i + my_strlen(src)] = '\0';
    return (result);
}


char *my_strconcat(char *dest, char const *src)
{
    int one = my_strlen(dest);
    int two = my_strlen(src);
    char *result = malloc(sizeof(char) * (one + two + 1));
    int i = 0;
    int j = 0;

    if (result == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    for (; src[j] != '\0'; j++, i++)
        result[i] = src[j];
    result[i] = '\0';
    return (result);
}
