/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-mehdi.djendar
** File description:
** error_two
*/

#include "my.h"
#include "corewar.h"

int error_and(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_or(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_xor(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}

int error_zjmp(char **params)
{
    if (params[2] != NULL)
        return (84);
    return (0);
}

int error_ldi(char **params)
{
    if (params[4] != NULL)
        return (84);
    return (0);
}