/*
** EPITECH PROJECT, 2022
** init_struct
** File description:
** init_struct
*/

#include "my.h"
#include "corewar.h"
#include "op.h"
#include <stdint.h>

static char **init_instruction(header_t *header, char *str, char **array)
{
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
    my_rev_bit((uint8_t*)&header->magic, 4);
    my_rev_bit((uint8_t*)&header->prog_size, 4);
    array = str_to_word(str, '\n');
    return (array);
}

char *before_getline(char *str, FILE *fd, char *path, header_t *header)
{
    struct stat stats;

    if (stat(path, &stats) == -1)
        return (NULL);
    str = malloc(sizeof(char) * (stats.st_size + 1));
    str[0] = '\0';
    if (str == NULL || fd == NULL)
        return (NULL);
    if (error_before_getline(path) == 84)
        return (NULL);
    return (str);
}

char **init_struct(header_t *header, char *path, int count, char **array)
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *fd = fopen(path, "r");
    ssize_t size_str = 0;
    char *str = NULL;

    str = before_getline(str, fd, path, header);
    if (str == NULL)
        return (NULL);
    while ((size_str = getline(&buffer, &size, fd)) > 0) {
        if (buffer == NULL)
            return (NULL);
        if (buffer[0] == COMMENT_CHAR)
            continue;
        buffer[size_str] = '\0';
        array = str_to_word(buffer, '"');
        if (error_handling(buffer) == 84)
            return (NULL);
        check_champ_info(header, count, array);
        if (count >= 2)
            strcat(str, buffer);
        count++;
    }
    array = init_instruction(header, str, array);
    return (array);
}
