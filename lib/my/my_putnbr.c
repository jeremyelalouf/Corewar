/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_put_nbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + 48);
}

void my_put_nberr(int nb)
{
    if (nb < 0) {
        my_putcherr('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putcherr(nb + 48);
}
