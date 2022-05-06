/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** my_memset
*/

void my_memset(char *s, int c, int n)
{
    int i = 0;

    for (i = 0; i != n; i++)
        s[i] = c;
}
