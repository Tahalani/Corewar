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

int handle_options(int fd, char *target, count_t *count_sruct)
{
    int return_value = 0;

    for (int count = 0; count != 16; count++) {
        for (int i = 0; target[i] != '\0'; i++) {
            if (target[i] == LABEL_CHAR && (target[i + 1] == '\n' ||
            target[i + 1] == '\0'))
                return (-1);
        }
        if (strcmp(target, OPT_ARRAY[count]) == 0) {
            return_value = (*OPT_FUNC[count]) (fd, count_sruct);
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
    count_t *count_sruct = malloc(sizeof(count_t));
    char **array = NULL;
    char **array_line = NULL;
    int fd = 0;
    int check = 0;
    char *name_file = malloc(sizeof(char) * (my_strlen(av[1]) + 5));

    for (int i = 0; av[1][i] != '.' && av[1][i] != '\0'; i++)
        name_file[i] = av[1][i];
    strcat(name_file, ".cor");
    if ((array = init_struct(header, path, 0, array)) == NULL)
        return (-1);
    if ((fd = write_name_comment(*header, name_file)) == -1)
        return (-1);
    for (unsigned int i = 0; array[i] != NULL; i++) {
        array_line = my_str_to_word_array(array[i], ' ');
        for (int i = 0; array_line[i]; i++)
            printf("non = %s\n", array_line[i]);
        for (unsigned int k = 0; array_line[k] != NULL; k++) {
            check = handle_options(fd, array_line[k], count_sruct);
            if (k == 0 && check != -1 && ((strstr(array_line[k], "zjmp") ==
            NULL && (strstr(array_line[k], "live")) == NULL &&
            (strstr(array_line[k], "fork")) == NULL && (strstr(array_line[k],
            "lfork")) == NULL)))
                write_total_arg(fd, array_line, count_sruct);
            else if (k != 0)
                write_arg(fd, array_line[k], array_line[0], count_sruct);
        }
    }
    printf("header: [%d]\n", count_sruct->byte);
    return (0);
}
