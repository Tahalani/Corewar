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

char *before_getline(char *str, FILE *fd, char *path)
{
    str = malloc(sizeof(char) * (4000));
    str[0] = '\0';
    if (str == NULL || fd == NULL)
        return (NULL);
    if (error_before_getline(path) == 84)
        return (NULL);
    return (str);
}

int init_sctuct2(char **array, char *buffer, int count, header_t *header)
{
    array = str_to_word(buffer, '"');
    if (error_handling(buffer) == 84)
        return (-1);
    check_champ_info(header, count, array);
    return (0);
}

char **init_struct(header_t *header, char *path, int count, char **array)
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *fd = fopen(path, "r");
    ssize_t size_str = 0;
    char *str = NULL;

    if ((str = before_getline(str, fd, path)) == NULL)
        return (NULL);
    while ((size_str = getline(&buffer, &size, fd)) > 0) {
        if (buffer == NULL)
            return (NULL);
        if (buffer[0] == COMMENT_CHAR)
            continue;
        buffer[size_str] = '\0';
        if (init_sctuct2(array, buffer, count, header) == -1)
            return (NULL);
        if (count >= 2)
            str = my_strcat(str, buffer);
        count++;
    }
    array = init_instruction(header, str, array);
    return (array);
}
