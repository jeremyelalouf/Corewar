/*
** EPITECH PROJECT, 2022
** mylib
** File description:
** my_charislower
*/

#include "my.h"

int my_char_islower(const char character)
{
    if (character >= 97 && character <= 122)
        return TRUE;
    return SUCC;
}
