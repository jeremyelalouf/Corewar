/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_char_is_num
*/

#include "my.h"

int my_char_isnum(const char c)
{
    if (c > 57 || c < 48)
        return SUCC;
    else
        return TRUE;
}
