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

char *loop_in_condition_option(int k, count_t *co, char *target, int *line)
{
    char *count_byte = NULL;
    char *line_str = NULL;

    if (k == 0 && co->check != 1) {
        co->label_array[co->count_label] = target;
        count_byte = int_to_str(co->byte);
        line_str = int_to_str(*line);
        if (count_byte[0] == '\0')
            count_byte[0] = '0';
        if (line_str[0] == '\0')
            line_str[0] = '0';
        co->label_array[co->count_label + 1] = line_str;
        co->label_array[co->count_label + 2]
        = count_byte;
        co->count_label += 3;
        co->check = 1;
    }
    return (target);
}

int condition_handle_option(int count, int fd, char *target, count_t *co)
{
    int return_value = 0;

    for (int i = 0; target[i] != '\0'; i++) {
        target = loop_in_condition_option(co->k, co, target, &co->line);
        if (target[i] == LABEL_CHAR && (target[i + 1] == '\n' ||
        target[i + 1] == '\0'))
            return (-1);
    }
    if (my_strcmp(target, OPT_ARRAY[count]) == 0) {
        return_value = (*OPT_FUNC[count]) (fd, co);
        return (2);
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

int loop_yolotron(char **array_line, int fd, count_t *count_sruct, int line)
{
    static int check = 0;
    int value_exit = 0;

    for (unsigned int k = 0; array_line[k] != NULL; k++) {
        count_sruct->line = line;
        check = handle_options(fd, array_line[k], count_sruct, k);
        if (k == 0 && check != -1 && ((my_strstr(array_line[k], "zjmp") ==
        NULL && (my_strstr(array_line[k], "live")) == NULL &&
        (my_strstr(array_line[k], "fork")) == NULL && (my_strstr(array_line[k],
        "lfork")) == NULL)))
            write_total_arg(fd, array_line, count_sruct);
        else if (k != 0) {
            count_sruct->line = line;
            value_exit = write_arg
            (fd, array_line[k], array_line[0], count_sruct);
        }
        if (value_exit == 84)
            return (84);
    }
    return (check);
}

int yolotron_asm(char *path, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    count_t *count_sruct = malloc(sizeof(count_t));
    char **array = NULL;
    char **array_line = NULL;
    int fd = 0;
    char *name_file = malloc(sizeof(char) * (my_strlen(av[1]) + 3));

    name_file = init_struct_count(count_sruct, name_file, av);
    if ((array = init_struct(header, path, 0, array)) == NULL)
        return (-1);
    if ((fd = write_name_comment(*header, name_file)) == -1)
        return (-1);
    for (unsigned int i = 0; array[i] != NULL; i++) {
        array_line = my_str_to_word_array(array[i], ' ');
        if (loop_yolotron(array_line, fd, count_sruct, i) == 84)
            return (-1);
    }
    write_label(fd, count_sruct);
    write_finally_prog_size(header, count_sruct, fd);
    return (0);
}
