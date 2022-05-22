/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-mehdi.djendar
** File description:
** error_three
*/

#include "my.h"
#include "corewar.h"

int error_sti(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_fork(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}

int error_lld(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}

int error_lldi(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_lfork(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}
