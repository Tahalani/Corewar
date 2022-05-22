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

ssize_t my_file_in_str_main(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    ssize_t size_real_buff;

    buffer = malloc(sizeof(char) * (4000));
    size_real_buff = read(fd, buffer, 4000);
    close(fd);
    return (size_real_buff);
}

int condition_good_result(char **av)
{
    char *real_file = NULL;
    char *name_file = malloc(sizeof(char) * (my_strlen(av[1]) + 3));
    char *name_buffer = create_real_file(av);
    int fd = 0;
    ssize_t size_real_buff;

    real_file = my_file_in_str(name_buffer);
    size_real_buff = my_file_in_str_main(name_buffer);
    name_file[my_strlen(av[1]) - 2] = '\0';
    for (int i = 0; av[1][i] != '.' && av[1][i] != '\0'; i++)
        name_file[i] = av[1][i];
    name_file = my_strcat(name_file, ".cor\0");
    fd = open(name_file, O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);
    write(fd, real_file, size_real_buff);
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
