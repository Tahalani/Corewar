/*
** EPITECH PROJECT, 2022
** base_corewar
** File description:
** corewar
*/

#include "my.h"
#include "corewar.h"
#include "option_asm.h"
#include "op.h"

typedef struct struct_header {
    int magic;
    char name[128];
    int prog_size;
    char comment[2048];
} __attribute__ ((packed));

int handle_options(int fd, char *array)
{
    int return_value = 0;

    for (int count = 0; count != 4; count++) {
        if (strcmp(array, OPT_ARRAY[count]) == 0) {
            return_value = (*OPT_FUNC[count]) (fd);
            return (2);
        }
    }
    return (return_value);
}

int write_aff(int fd)
{
    char c = 10;

    write(fd, &c, 1);
    return (0);
}

char **init_struct(header_t *header, char *path, int count, char **array)
{
    char *str = NULL;
    size_t size = 0;
    FILE *fd = fopen(path, "r");
    char *buffer = malloc(sizeof(char) * 500);
    ssize_t size_str = 0;

    buffer[0] = '\0';
    while ((size_str = getline(&str, &size, fd)) > 0) {
        str[size_str - 1] = '\0';
        array = str_to_word(str, '"');
        if (count == 0) {
            memset(header->prog_name, 0, PROG_NAME_LENGTH);
            strcpy(header->prog_name, array[1]);
        }
        if (count == 1) {
            memset(header->comment, 0, COMMENT_LENGTH);
            strcpy(header->comment, array[1]);
        }
        if (count > 2)
            strcat(buffer, str);
        count++;
    }
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 23;
    array = str_to_word(buffer, ' ');
    return (array);
}

int yolotron_asm(char *path, char **av)
{
    header_t header;
    char **array = NULL;
    int fd = 0;

    array = init_struct(&header, path, 0, array);
    fd = open(av[2], O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);
    if (fd == -1)
        return (-1);
    write(fd, &header, sizeof(header_t));
    write_sti(fd);
    return (0);
}
