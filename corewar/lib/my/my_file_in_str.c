/*
** EPITECH PROJECT, 2022
** my_file_in_str
** File description:
** lib
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

char *my_file_in_str(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (4000));
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, 4000) == -1)
        return (NULL);
    buffer[4000] = '\0';
    close(fd);
    return (buffer);
}
