/*
** EPITECH PROJECT, 2022
** bscorewar
** File description:
** option_asm
*/

#ifndef OPTION_ASM_H_
    #define OPTION_ASM_H_
    #include "corewar.h"

static int (*OPT_FUNC[]) (int fd) = {
    write_live,
    write_ld,
    write_st,
    write_add,
    write_sub,
    write_and,
    write_or,
    write_xor,
    write_zjmp,
    write_ldi,
    write_sti,
    write_fork,
    write_lld,
    write_lldi,
    write_lfork,
    write_aff
};

static const char *OPT_ARRAY[] = {
    "live",
    "ld",
    "st",
    "add",
    "sub",
    "and",
    "or",
    "xor",
    "zjmp",
    "ldi",
    "sti",
    "fork",
    "lld",
    "lldi",
    "lfork",
    "aff"
};

#endif/* !OPTION_ASM_H_ */
