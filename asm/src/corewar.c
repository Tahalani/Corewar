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

int print_name_in_128(int fd)
{
    struct struct_header header = {
        .magic = 15369203,
        .name = "zork",
        .prog_size = 23,
        .comment = "just a basic living program"
    };
    write(fd, &header, sizeof(header));
    return (0);
}

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

int print_in_char(int fd, char c)
{
    write(fd, &c, 1);
    return (0);
}

char **init_struct(char *path)
{
    char *str = NULL;
    size_t size = 0;
    FILE *fd = fopen(path, "r");
    char *buffer = malloc(sizeof(char) * 500);
    buffer[0] = '\0';
    ssize_t size_str = 0;
    int count = 0;
    header_t *header = malloc(sizeof(header_t));

    while ((size_str = getline(&str, &size, fd)) > 0) {
        str[size_str - 1] = '\0';
        char **array = str_to_word(str, '"');
        if (count == 0)
            header->name = array[2];
        if (count == 1)
            header->comment = array[2];
        if (count > 2)
            strcat(buffer, str);
        count++;
    }
    header->magic = 15369203;
    header->prog_size = 23;
    char **array = str_to_word(buffer, ' ');
    // for (int i = 0; array[i] != NULL; i++) {
    //     printf("array[%d] = [%s]\n", i, array[i]);
    // }
    //write(fd, &header, sizeof(header));
    return (array);
}

int yolotron_asm(char *path, char **av)
{
    char **array = init_struct(path);
    // rows = my_str_to_word_array(buffer, '\n');
    // for (int i = 0; rows[i]; i++) {
    //     cols = my_str_to_word_array(rows[i], ' ');
    //     print_name_in_128(fd);
    //     print_in_char(fd, 11); // sti
    //     print_in_char(fd, 1); // registre
    //     print_in_char(fd, 1); // registre
    //     print_in_char(fd, 6); // AND//
    // }
    return (0);
}
