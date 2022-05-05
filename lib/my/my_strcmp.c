/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compare two strings
*/

#include <unistd.h>
#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    if (s1 == s2)
        return SUCC;
    if (s2 == NULL || s1 == NULL)
        return ERR;
    for (; *s1 == *s2; ++s1, ++s2) {
        if (*s1 == 0)
            return 0;
    }
    return *(char *)s1 - *(char *)s2;
}
