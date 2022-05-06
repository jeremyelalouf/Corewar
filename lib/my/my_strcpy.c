/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** my_strcpy
*/

char * my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
