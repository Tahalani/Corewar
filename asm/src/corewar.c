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

int handle_options(int fd, char *target)
{
    int return_value = 0;

    for (int count = 0; count != 16; count++) {
        for (int i = 0; target[i] != '\0'; i++) {
            if (target[i] == ':' && (target[i + 1] == '\n' ||
            target[i + 1] == '\0'))
                return (-1);
        }
        if (strcmp(target, OPT_ARRAY[count]) == 0) {
            return_value = (*OPT_FUNC[count]) (fd);
            return (2);
        }
    }
    return (return_value);
}

int write_name_comment(header_t header, char *file)
{
    int fd = open(file, O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);

    if (fd == -1)
        return (-1);
    write(fd, &header, sizeof(header_t));
    return (fd);
}

int yolotron_asm(char *path, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    char **array = NULL;
    char **array_line = NULL;
    int fd = 0;
    int check = 0;

    if ((array = init_struct(header, path, 0, array)) == NULL)
        return (-1);
    if ((fd = write_name_comment(*header, av[2])) == -1)
        return (-1);
    for (unsigned int i = 1; array[i] != NULL; i++) {
        array_line = str_to_word(array[i], ' ');
        for (unsigned int k = 0; array_line[k] != NULL; k++) {
            if (k == 0)
                check = handle_options(fd, array_line[k]);
            if (k == 0 && check != -1)
                write_total_arg(fd, array_line);
            else if (k != 0)
                write_arg(fd, array_line[k]);
        }
    }
    return (0);
}
