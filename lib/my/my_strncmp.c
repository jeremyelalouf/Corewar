/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

#include <stdlib.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == s2)
        return SUCC;
    if (s2 == NULL || s1 == NULL)
        return ERR;
    for (; n != 0 && *s1 == *s2; ++s1, ++s2, --n) {
        if (*s1 == 0)
            break;
    }
    if (n == 0)
        return 0;
    return *(char *)s1 - *(char *)s2;
}
