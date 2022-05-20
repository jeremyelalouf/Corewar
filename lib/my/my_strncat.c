/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(const char *str);

char *my_strncat(char *dest, const char *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return (dest);
}
