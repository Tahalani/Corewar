/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** the .h of project
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>

typedef struct champion_s {
    char *file_name;
    int prog_nbr;
    int adress;
    int is_valid;
} champion_t;

typedef struct corewar_s {
    int nbr_champ;
    int nbr_dump;
} corewar_t;

void free_struct(corewar_t corewar, champion_t *champion);
int set_random_number_adress(corewar_t *corewar, champion_t *champion);
int get_champ_adress(champion_t *champion, char **av, int i);
int get_prog_nbr(champion_t *champion, int ac, char **av, int i);
champion_t *parsing_argument(int ac, char **av, corewar_t *corewar);

#endif /* COREWAR_H_ */
