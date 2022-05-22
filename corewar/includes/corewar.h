/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** the .h of project
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include "op.h"
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <stdint.h>

typedef struct champion_s {
    char *file_name;
    int prog_nbr;
    int adress;
    int pc;
    int waiting;
    int is_valid;
    int carry;
    int living;
    int reg[REG_NUMBER];
    uint8_t *buf_cmd;
    header_t header;
} champion_t;

typedef struct corewar_s {
    int nbr_champ;
    int nbr_dump;
} corewar_t;


int insert_champ(uint8_t *mem, champion_t *champion);
void verif_adress(uint8_t *mem, champion_t *champion);
int parsing_file(champion_t *champion, char *file);
void free_struct(corewar_t corewar, champion_t *champion);
int set_random_number_adress(corewar_t *corewar, champion_t *champion);
int get_champ_adress(champion_t *champion, char **av, int i);
int get_prog_nbr(champion_t *champion, int ac, char **av, int i);
champion_t *parsing_argument(int ac, char **av, corewar_t *corewar);
void show_mem(uint8_t *mem);
uint8_t *mem_alloc(void);
int insert_mem(uint8_t *mem, champion_t *champion);
uint8_t *my_revint(uint8_t *str, unsigned int len);
uint8_t *read_bytecode(uint8_t bytecode);
unsigned int read_mem(int index, int size, uint8_t *mem);
int fill_arg(int *arg, uint8_t *arg_type, uint8_t *mem, int *pc);
uint32_t conv_endian4(uint32_t nb);
void free_struct(corewar_t corewar, champion_t *champion);
uint8_t *sti_arg_pars(uint8_t *arg_type, uint8_t *arg_index);
void struct_init(champion_t *champion);

void live(int *pc, champion_t *champion, uint8_t *mem);
void ld(int *pc, champion_t *champion, uint8_t *mem);
void st(int *pc, champion_t *champion, uint8_t *mem);
void add(int *pc, champion_t *champion, uint8_t *mem);
void sub(int *pc, champion_t *champion, uint8_t *mem);
void and(int *pc, champion_t *champion, uint8_t *mem);
void or(int *pc, champion_t *champion, uint8_t *mem);
void xor(int *pc, champion_t *champion, uint8_t *mem);
void zjmp(int *pc, champion_t *champion, uint8_t *mem);
void ldi(int *pc, champion_t *champion, uint8_t *mem);
void sti(int *pc, champion_t *champion, uint8_t *mem);
void lld(int *pc, champion_t *champion, uint8_t *mem);
void lldi(int *pc, champion_t *champion, uint8_t *mem);
void aff(int *pc, champion_t *champion, uint8_t *mem);
void lfork(int *pc, champion_t *champion, uint8_t *mem);

extern void (*mne[16])(int *, champion_t *, uint8_t *);

#endif /* COREWAR_H_ */
