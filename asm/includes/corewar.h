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
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdint.h>
    #include "op.h"

typedef struct count_s {
    int byte;
    char **label_array;
    int count_label;
    char **get_label;
    int count_distance;
    int check;
    int size;
    int line;
    int k;
} count_t;

typedef struct arg_byte_s {
    char *mnemonic;
    int byte;
} arg_byte_t;

static const struct arg_byte_s ARG[] = {
    {"live", DIR_SIZE},
    {"ld", DIR_SIZE},
    {"add", DIR_SIZE},
    {"sub", DIR_SIZE},
    {"and", DIR_SIZE},
    {"or", DIR_SIZE},
    {"xor", DIR_SIZE},
    {"zjmp", 2},
    {"ldi", 2},
    {"sti", 2},
    {"st", DIR_SIZE},
    {"fork", 2},
    {"lld", DIR_SIZE},
    {"lldi", 2},
    {"lfork", 2},
    {"aff", DIR_SIZE},
};

char *init_struct_count(count_t *count_sruct, char *name_file, char **av);

int condition_handle_option(int count,
int fd, char *target, count_t *co);

uint8_t *my_rev_bit(uint8_t *str, unsigned int len);

int check_champ_info(header_t *header, int count, char **array);

int write_finally_prog_size(header_t *header, count_t *count_sruct, int fd);

int error_before_getline(char *path);

int write_wome_text(void);

int write_a_number_as_int(void);

int without_padding(void);

int with_padding(void);

char *int_to_str(int number);

int write_total_arg(int fd, char **array_line, count_t *count_sruct);

int write_arg(int fd, char *array_line, char *mnemonic, count_t *co);

char **str_to_word(char const *str, char separator);

int write_modulo(int fd, char *post_modulo, char *mnemonic, count_t *co);

int handle_options(int fd, char *, count_t *count_sruct, int k);

int yolotron(char *path);

int yolotron_asm(char *path, char **av);

int write_live(int fd, count_t *count_sruct);

int write_ld(int fd, count_t *count_sruct);

int write_st(int fd, count_t *count_sruct);

int write_add(int fd, count_t *count_sruct);

int write_sub(int fd, count_t *count_sruct);

int write_and(int fd, count_t *count_sruct);

int write_aff(int fd, count_t *count_sruct);

int write_label(int fd, count_t *count_sruct);

int write_or(int fd, count_t *count_sruct);

int write_xor(int fd, count_t *count_sruct);

int write_zjmp(int fd, count_t *count_sruct);

int write_ldi(int fd, count_t *count_sruct);

int write_sti(int fd, count_t *count_sruct);

int write_fork(int fd, count_t *count_sruct);

int write_lld(int fd, count_t *count_sruct);

int write_lldi(int fd, count_t *count_sruct);

int write_lfork(int fd, count_t *count_sruct);

int write_aff(int fd, count_t *count_sruct);

int write_register(int fd, char *post_register, count_t *count_sruct);

char **init_struct(header_t *header, char *path, int count, char **array);

int error_live(char **params);

int error_ld(char **params);

int error_st(char **params);

int error_add(char **params);

int error_sub(char **params);

int error_and(char **params);

int error_aff(char **params);

int error_or(char **params);

int error_xor(char **params);

int error_zjmp(char **params);

int error_ldi(char **params);

int error_sti(char **params);

int error_fork(char **params);

int error_lld(char **params);

int error_lldi(char **params);

int error_lfork(char **params);

int error_aff(char **params);

int error_handling(char *buffer);

int error_options(char **params);

int decim_to_bin(void);

#endif/* !PROJET_H_ */
