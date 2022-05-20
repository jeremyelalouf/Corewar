/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_bswap
*/

#include <stddef.h>
#include <stdint.h>

#include "my.h"

void my_bswap(void *value, size_t size)
{
    uint8_t *tmp = (uint8_t *)value;
    uint8_t c;

    for (size_t i = 0; i < size / 2; i++) {
        c = tmp[i];
        tmp[i] = tmp[size - i - 1];
        tmp[size - i - 1] = c;
    }
}
