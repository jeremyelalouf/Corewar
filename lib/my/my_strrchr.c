/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_strrchr
*/

#include <stddef.h>

char *my_strrchr(const char *string, int c)
{
    int c_index = 0;

    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == (char)c)
            c_index = i + 1;
    }
    if (c_index - 1 == 0)
        return NULL;
    return (char *)string + c_index;
}
