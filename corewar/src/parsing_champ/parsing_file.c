/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "my.h"
#include "corewar.h"

uint32_t conv_endian4(uint32_t nb)
{
    uint32_t part[4] = {0};
    uint32_t res = 0;

    part[0] = (nb & 0x000000ff) << 24u;
    part[1] = (nb & 0x0000ff00) << 8u;
    part[2] = (nb & 0x00ff0000) >> 8u;
    part[3] = (nb & 0xff000000) >> 24u;
    res = part[0] | part[1] | part[2] | part[3];
    write(1, &res, sizeof(nb));
    return res;
}

uint8_t *my_revint(uint8_t *str, unsigned int len)
{
    uint8_t c;

    for (unsigned int i = 0; i < len; i++, len--) {
        c = str[i];
        str[i] = str[len - 1];
        str[len - 1] = c;
    }
    return (str);
}

int parsing_file(champion_t *champion, char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return 84;
    if (read(fd, &champion->header, sizeof(header_t)) == -1)
        return 84;
    my_revint((uint8_t *)&champion->header.magic, 4);
    my_revint((uint8_t *)&champion->header.prog_size, 4);
    if (champion->header.prog_size <= 0)
        return 84;
    champion->buf_cmd = malloc(sizeof(uint8_t) *
    (champion->header.prog_size + 1));
    champion->buf_cmd[champion->header.prog_size] = '\0';
    if (champion->buf_cmd == NULL)
        return 84;
    if (read(fd, champion->buf_cmd, champion->header.prog_size) == -1)
        return 84;
    return 0;
}