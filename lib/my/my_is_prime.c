/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_is_prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return SUCC;
    while (i < nb) {
        if (nb / i * i == nb)
            i++;
        return SUCC;
    }
    return TRUE;
}
