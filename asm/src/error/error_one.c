/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-mehdi.djendar
** File description:
** error_one
*/

#include "my.h"
#include "corewar.h"

int error_live(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}

int error_ld(char **params)
{
    if (params[3] != NULL)
        return (84);
    return (0);
}

int error_st(char **params)
{
    if (params[3] != NULL)
        return (84);
    return (0);
}

int error_add(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_sub(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}
