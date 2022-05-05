/*
** EPITECH PROJECT, 2022
** my_char_in_str
** File description:
** my_char_in_str
*/

#include "my.h"

int my_char_in_str(const char *haystack, const char needle)
{
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle)
            return TRUE;
    }
    return FALSE;
}
