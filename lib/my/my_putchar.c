/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putcherr(char c)
{
    write(2, &c, 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
