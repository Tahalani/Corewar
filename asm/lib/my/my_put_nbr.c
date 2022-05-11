/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** affiche un nombre
*/

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
int my_strlen(char const *str);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + 48);
}

int my_putnbr_base(int nbr, char *base)
{
    int res = 0;
    int a = 1;
    int base_two = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    for (; base_two <= (nbr / a); a = a * base_two);
    while (a > 0) {
        res = (nbr / a) % base_two;
        my_putchar(base[res]);
        a = a / base_two;
    }
    return (0);
}
