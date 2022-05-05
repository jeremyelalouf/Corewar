/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] < 48 || str[a] > 57)
            return SUCC;
        a++;
    }
    return TRUE;
}
