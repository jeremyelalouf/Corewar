/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stddef.h>

#include "my.h"

char *my_strstr(char const *str, char const *to_find)
{
    char *dup = my_strdup(str);
    char *tmp = dup;
    int i = 0;

    while (*dup != '\0') {
        if (*dup == *to_find && my_strncmp(to_find,
            dup, my_strlen(to_find)) == 0)
            break;
        dup++;
        i++;
    }
    if (*dup == '\0') {
        return NULL;
        free(tmp);
    }
    free(tmp);
    return ((char *)str + i);
}
