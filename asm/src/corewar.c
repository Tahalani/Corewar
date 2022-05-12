/*
** EPITECH PROJECT, 2022
** base_corewar
** File description:
** corewar
*/

#include "my.h"
#include "corewar.h"
#include "option_asm.h"

typedef struct struct_header {
    int magic;
    char name[128];
    int prog_size;
    char comment[2048];
} __attribute__ ((packed));

// int handle_options(int fd, char **cols)
// {
//     int return_value = 0;

//     for (int count = 0; count != 4; count++) {
//         if (strcmp(cols[0], OPT_ARRAY[count]) == 0) {
//             return_value = (*OPT_FUNC[count]) (fd, cols);
//             break;
//         }
//     }
//     return (return_value);
// }

int write_aff(int fd)
{
    char c = 10;

    write(fd, &c, 1);
    return (0);
}

// int print_in_char(int fd, char c)
// {
//     write(fd, &c, 1);
//     return (0);
// }

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
        if (count == 0)
            header->name = array[1];
        if (count == 1)
            header->comment = array[1];
        if (count > 2)
            strcat(buffer, str);
        count++;
    }
    header->magic = 15369203;
    header->prog_size = 23;
    array = str_to_word(buffer, ' ');
    return (array);
}

int yolotron_asm(char *path, char **av)
{
    header_t *header = malloc(sizeof(header_t));
    char **array = NULL;

    // header->name = malloc(sizeof(char) * 128);
    // header->comment = malloc(sizeof(char) * 2048);
    array = init_struct(header, path, 0, array);
    int fd = open(av[2], O_CREAT | O_RDWR, S_IRUSR | S_IRGRP | S_IROTH);
    struct struct_header st_header = {
        .magic = header->magic,
        .name = header->name,
        .prog_size = header->prog_size,
        .comment = header->comment
    };
    printf("%s\n", st_header.name);
    printf("%s\n", st_header.comment);
    printf("%d\n", st_header.magic);
    printf("%d\n", st_header.prog_size);
    write(fd, &st_header, sizeof(st_header));
    // write_champion(header, array);
    return (0);
}
