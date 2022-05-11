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

typedef struct header_s {
    int magic;
    char *name;
    int prog_size;
    char *comment;
} header_t;

int write_wome_text(void);

int write_a_number_as_int(void);

int without_padding(void);

int with_padding(void);

int print_add(int fd, char **cols);

int print_sub(int fd, char **cols);

int print_mul(int fd, char **cols);

int print_put(int fd, char **cols);

int print_name(int fd, char **cols);

char **str_to_word(char const *str, char separator);

int handle_options(int fd, char **cols);

int yolotron(char *path);

int yolotron_asm(char *path, char **av);

int write_live(int fd);

int write_ld(int fd);

int write_st(int fd);

int write_add(int fd);

int write_sub(int fd);

int write_and(int fd);

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

#endif/* !PROJET_H_ */
