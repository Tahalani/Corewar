/*
** EPITECH PROJECT, 2022
** init_struct
** File description:
** init_struct
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

static int check_champ_info(header_t *header, int count, char **array)
{
    if (count == 0) {
        memset(header->prog_name, 0, PROG_NAME_LENGTH);
        strcpy(header->prog_name, array[1]);
    }
    if (count == 1) {
        memset(header->comment, 0, COMMENT_LENGTH);
        strcpy(header->comment, array[1]);
    }
    return (0);
}

static char **init_instruction(header_t *header, char *str, char **array)
{
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 23;
    array = str_to_word(str, ' ');
    return (array);
}

char **init_struct(header_t *header, char *path, int count, char **array)
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *fd = fopen(path, "r");
    char *str = malloc(sizeof(char) * 500);
    ssize_t size_str = 0;

    str[0] = '\0';
    if (str == NULL || fd == NULL)
        return (NULL);
    while ((size_str = getline(&buffer, &size, fd)) > 0) {
        if (buffer == NULL)
            return (NULL);
        buffer[size_str] = '\0';
        array = str_to_word(buffer, '"');
        check_champ_info(header, count, array);
        if (count >= 2)
            strcat(str, buffer);
        count++;
    }
    array = init_instruction(header, str, array);
    return (array);
}