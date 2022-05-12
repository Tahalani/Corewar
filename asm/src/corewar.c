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

int write_name_comment(header_t header, char *file)
{
    int fd = open(file, O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);

    if (fd == -1)
        return (-1);
    write(fd, &header, sizeof(header_t));
    return (0);
}

int yolotron_asm(char *path, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    char **array = NULL;

    // if (init_struct(header, path, 0, array) == NULL)
    //     return (-1);
    array = init_struct(header, path, 0, array);
    if (write_name_comment(*header, av[2]) == -1)
        return (-1);
    // write_sti(fd);
    return (0);
}
