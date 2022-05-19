/*
** EPITECH PROJECT, 2022
** starting
** File description:
** my_reallocarray
*/

#include <stdlib.h>

#include "my.h"

void *my_reallocarray(void *ptr, int nmemb, int size, int last_nmemb)
{
    void *result = NULL;

    if (ptr == NULL)
        return malloc(size * nmemb);
    result = malloc(size * nmemb);
    if (result == NULL)
        return NULL;
    my_memcpy(result, ptr, size * (nmemb - last_nmemb));
    free(ptr);
    return result;
}
