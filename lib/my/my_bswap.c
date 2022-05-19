/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_bswap
*/

#include <stddef.h>
#include <stdint.h>

void my_bswap(void *value, size_t size)
{
    uint8_t *tmp = (uint8_t *) value;
    uint8_t c;

    for (size_t i = 0; i < size / 2; i++) {
        c = tmp[i];
        tmp[i] = tmp[size - i - 1];
        tmp[size - i - 1] = c;
    }
}

int my_int_bswap(int value)
{
    int converted = 0;

    converted |= ((0xff & value) << 24);
    converted |= (((0xff << 8) & value) << 8);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 24) & value) >> 24);
    return converted;
}

int my_int_swapb(int value)
{
    int converted = 0;

    converted |= (((0xff << 24) & value) >> 24);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 8) & value) << 8);
    converted |= ((0xff & value) << 24);
    return converted;
}
