/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** islower
*/

#include "my.h"

int my_str_islower(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            return SUCC;
    }
    return TRUE;
}
