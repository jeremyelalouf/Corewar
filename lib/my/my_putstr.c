/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr_err(char const *str)
{
    while (*str != '\0') {
        my_putchar_err(*str);
        str++;
    }
    return SUCC;
}

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str++;
    }
    return SUCC;
}
