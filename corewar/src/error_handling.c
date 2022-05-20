/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int ac, UNUSED char const *av[])
{
    if (ac < 1)
        return ERR;
    return SUCC;
}
