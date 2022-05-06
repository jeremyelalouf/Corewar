/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
