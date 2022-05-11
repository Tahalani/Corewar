/*
** EPITECH PROJECT, 2022
** bscorewar
** File description:
** asm
*/

#include "my.h"
#include "corewar.h"

int print_add(int fd, char **cols)
{
    int int_cols_one = my_getnbr(cols[1]);
    int int_cols_two = my_getnbr(cols[2]);
    void *tmp = &int_cols_one;
    void *tmp_two = &int_cols_two;
    char add = 4;

    write(fd, &add, 1);
    write(fd, tmp, sizeof(int));
    write(fd, tmp_two, sizeof(int));
    return (0);
}

int print_sub(int fd, char **cols)
{
    int int_cols_one = my_getnbr(cols[1]);
    int int_cols_two = my_getnbr(cols[2]);
    void *tmp = &int_cols_one;
    void *tmp_two = &int_cols_two;
    char sub = 5;

    write(fd, &sub, 1);
    write(fd, tmp, sizeof(int));
    write(fd, tmp_two, sizeof(int));
    return (0);
}

int print_mul(int fd, char **cols)
{
    int int_cols_one = my_getnbr(cols[1]);
    int int_cols_two = my_getnbr(cols[2]);
    void *tmp = &int_cols_one;
    void *tmp_two = &int_cols_two;
    char mul = 3;

    write(fd, &mul, 1);
    write(fd, tmp, sizeof(int));
    write(fd, tmp_two, sizeof(int));
    return (0);
}

int print_put(int fd, char **cols)
{
    char put = 4;
    int len_word = my_strlen(cols[1]);

    write(fd, &put, 1);
    write(fd, &len_word, sizeof(int));
    write(fd, cols[1], my_strlen(cols[1]));
    return (0);
}

int print_live(int fd, char **cols)
{
    int int_cols_one = my_getnbr(cols[1]);
    void *tmp = &int_cols_one;
    char live = 1;

    write(fd, &live, 1);
    write(fd, tmp, sizeof(int));
    return (0);
}

int print_name(int fd, char **cols)
{
    char name = 4;

    printf("name = %s\n", cols[1]);
    write(fd, cols[1], 32);
    write(fd, "*\n", 2);
    return (0);
}
// direct = valeur de la var, indirect = addresse