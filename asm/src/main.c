/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "corewar.h"

char *create_real_file(char **av)
{
    char *name_file = malloc(sizeof(char) * (my_strlen(av[1]) + 3));

    name_file[my_strlen(av[1]) - 2] = '\0';
    for (int i = 0; av[1][i] != '.' && av[1][i] != '\0'; i++)
        name_file[i] = av[1][i];
    name_file = my_strcat(name_file, ".lol\0");
    return (name_file);
}

int condition_good_result(char **av)
{
    struct stat stats;
    char *real_file = NULL;
    char *name_file = malloc(sizeof(char) * (my_strlen(av[1]) + 3));
    char *name_buffer = create_real_file(av);
    int fd = 0;

    real_file = my_file_in_str(name_buffer);
    name_file[my_strlen(av[1]) - 2] = '\0';
    for (int i = 0; av[1][i] != '.' && av[1][i] != '\0'; i++)
        name_file[i] = av[1][i];
    name_file = my_strcat(name_file, ".cor\0");
    stat(name_buffer, &stats);
    fd = open(name_file, O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);
    write(fd, real_file, stats.st_size);
    return (0);
}

int main(int ac, char **av)
{
    int result = 0;

    if (ac != 2)
        return (84);
    result = yolotron_asm(av[1], av);
    if (result == -1)
        return (84);
    if (result != 1)
        condition_good_result(av);
    return (0);
}
