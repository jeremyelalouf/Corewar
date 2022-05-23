/*
** EPITECH PROJECT, 2022
** starting
** File description:
** my_realloc
*/

#include <stdlib.h>

#include "my.h"

void *my_realloc(void *ptr, int size, int nmemb, int last_nmemb)
{
    void *new = NULL;

    if (size != 0) {
        if (ptr == NULL)
            return malloc(size * nmemb);
        new = malloc(size * nmemb);
        if (new) {
            my_memcpy(new, ptr, size * last_nmemb);
            free(ptr);
        }
    }
    return new;
}
