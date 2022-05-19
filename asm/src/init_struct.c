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
        return (1);
    }
    return (84);
}

static char **init_instruction(header_t *header, char *str, char **array)
{
    int tmp = COREWAR_EXEC_MAGIC;
    void *ptr = &(tmp);
    int result = *(int *)my_revstr(ptr);
    int result_int_magic = (int)result;
    int tmp_two = 23;
    void *ptr_two = &(tmp_two);
    int result_two = *(int *)my_revstr(ptr_two);
    int result_prog_size = (int)result_two;

    header->magic = result_int_magic;
    header->prog_size = result_prog_size;
    array = str_to_word(str, '\n');
    return (array);
}

char **init_struct(header_t *header, char *path, int count, char **array)
{
    char *buffer = NULL;
    size_t size = 0;
    struct stat stats;
    FILE *fd = fopen(path, "r");
    if (stat(path, &stats) == -1)
        return (NULL);
    char *str = malloc(sizeof(char) * (stats.st_size + 1));
    ssize_t size_str = 0;

    str[0] = '\0';
    if (str == NULL || fd == NULL)
        return (NULL);
    if (error_before_getline(path) == 84)
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