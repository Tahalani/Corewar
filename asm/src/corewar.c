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

    for (int count = 0; count != 17; count++) {
        printf("TARGET: [%s]\n", target);
        for (int i = 0; target[i] != '\0'; i++) {
            if (target[i] == ':' && (target[i + 1] == '\n' ||
            target[i + 1] == '\0'))
                return (0);
        }
        if (strcmp(target, OPT_ARRAY[count]) == 0) {
            // printf("%d\n", count);
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
    int fd = 0;

    if ((array = init_struct(header, path, 0, array)) == NULL)
        return (-1);
    if ((fd = write_name_comment(*header, av[2])) == -1)
        return (-1);
    for (unsigned int i = 0; array[i] != NULL; i++)
        handle_options(fd, array[i]);
    return (0);
}
