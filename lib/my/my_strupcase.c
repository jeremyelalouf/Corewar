/*
** EPITECH PROJECT, 2021
** strupcase
** File description:
** strupcase
*/

#include <string.h>

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    return (str);
}
