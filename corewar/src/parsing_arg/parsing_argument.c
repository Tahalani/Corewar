/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main of the program
*/

#include "my.h"
#include "corewar.h"

int my_extensioncmp(char *str1, char *str2, int size_cmp)
{
    int size_word = my_strlen(str2);
    int cpt = 0;

    if (size_word <= size_cmp)
        return -1;
    for (int i = size_word - 1; cpt != size_cmp; i--) {
        if (str1[size_cmp - cpt - 1] != str2[i])
            return (-1);
        cpt++;
    }
    return (0);
}

int initialize_option(champion_t *champion, int ac, char **av, int i)
{
    champion->file_name = my_strdup(av[i]);
    champion->prog_nbr = 0;
    champion->adress = -1;
    champion->is_valid = -1;
    int fd = open(av[i], O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 84;
    }
    if (get_prog_nbr(champion, ac, av, i) == 84)
        return 84;
    if (get_champ_adress(champion, av, i) == 84)
        return 84;
    champion->is_valid = 1;
    close(fd);
    return 0;
}

static void count_nbr_champ(char **av, int *nbr_champion, int ac,
corewar_t *corewar)
{
    for (int i = 1; i < ac; i++) {
        if (my_extensioncmp(".cor", av[i], 4) == 0)
            *nbr_champion += 1;
    }
    corewar->nbr_champ = *nbr_champion;
    return;
}

int set_dump_nbr(corewar_t *corewar, char **av, int i)
{
    if (my_strcmp(av[i], "-dump") == 0 && av[i + 1] != NULL) {
        if (my_str_isnum(av[i + 1]) == 1)
            corewar->nbr_dump = my_getnbr(av[i + 1]);
    }
    return 0;
}

champion_t *parsing_argument(int ac, char **av, corewar_t *corewar)
{
    int nbr_champion = 0;
    int cpt = 0;
    corewar->nbr_dump = 1536;

    count_nbr_champ(av, &nbr_champion, ac, corewar);
    if (nbr_champion == 0)
        return NULL;
    champion_t *champion = malloc(sizeof(champion_t) * (nbr_champion));
    for (int i = 1; i < ac; i++) {
        if (my_extensioncmp(".cor", av[i], 4) == 0) {
            initialize_option(&champion[cpt], ac, av, i);
            cpt++;
        }
        set_dump_nbr(corewar, av, i);
    }
    if (set_random_number_adress(corewar, champion) == 84) {
        free_struct(*corewar, champion);
        return NULL;
    }
    for (int i = 0; i < nbr_champion; i++) {
        printf("%s\n", champion[i].file_name);
        printf("%i\n", champion[i].prog_nbr);
        printf("name %s\n", champion[i].file_name);
        printf("number %i\n", champion[i].prog_nbr);
        printf("adress %i\n", champion[i].adress);
        printf("valid ? : %i\n", champion[i].is_valid);
        printf("val de dump_nbr ? : %i\n", corewar->nbr_dump);
    }
    return champion;
}