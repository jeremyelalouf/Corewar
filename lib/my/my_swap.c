/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *b;
    *b = *a;
    *a = c;
}
