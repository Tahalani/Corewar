/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-mehdi.djendar
** File description:
** error_asm
*/

#ifndef ERROR_ASM_H_
    #define ERROR_ASM_H_
    #include "corewar.h"

static int (*ERROR_FUNC[]) (char **params) = {
    error_live,
    error_ld,
    error_st,
    error_add,
    error_sub,
    error_and,
    error_or,
    error_xor,
    error_zjmp,
    error_ldi,
    error_sti,
    error_fork,
    error_lld,
    error_lldi,
    error_lfork,
    error_aff,
};

static const char *ERROR_ARRAY[] = {
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
    "aff",
};

#endif /* !ERROR_ASM_H_ */
