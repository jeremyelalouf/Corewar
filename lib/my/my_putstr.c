/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_putstr
*/

#include "my.h"

void my_putsterr(const char *str)
{
    while (*str != '\0'){
        my_putcherr(*str);
        str++;
    }
}

void my_putstr(const char *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str++;
    }
}
