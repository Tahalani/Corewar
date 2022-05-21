/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** return the smallest prime number
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strdup(char const *src);
int my_is_prime(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);

int my_find_prime_sup(int nb)
{
    for (; my_is_prime(nb) != 1; nb++);
    return (nb);
}

char *my_strstr(char const *str, char const *to_find)
{
    char *stock = my_strdup(str);
    char *tmp = stock;
    int i = 0;

    for (; *stock != '\0'; i++) {
        if (*stock == *to_find && my_strncmp(to_find,
            stock, my_strlen(to_find)) == 0)
            break;
        stock++;
    }
    if (*stock == '\0') {
        return NULL;
        free(tmp);
    }
    free(tmp);
    return ((char *)str + i);
}
