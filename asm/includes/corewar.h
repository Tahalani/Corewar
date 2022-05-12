/*
** EPITECH PROJECT, 2021
** projet.h
** File description:
** the .h of project
*/

#ifndef PROJET_H_
    #define PROJET_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include "op.h"

int write_wome_text(void);

int write_a_number_as_int(void);

int without_padding(void);

int with_padding(void);

char **str_to_word(char const *str, char separator);

int handle_options(int fd, char *array);

int yolotron(char *path);

int yolotron_asm(char *path, char **av);

int write_live(int fd);

int write_ld(int fd);

int write_st(int fd);

int write_add(int fd);

int write_sub(int fd);

int write_and(int fd);

int write_aff(int fd);

int write_or(int fd);

int write_xor(int fd);

int write_zjmp(int fd);

int write_ldi(int fd);

int write_sti(int fd);

int write_fork(int fd);

int write_lld(int fd);

int write_lldi(int fd);

int write_lfork(int fd);

int write_aff(int fd);

char **init_struct(header_t *header, char *path, int count, char **array);

#endif/* !PROJET_H_ */
