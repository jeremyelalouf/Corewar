/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** my_bswap
*/

int my_bswap(int value)
{
    int converted = 0;

    converted |= ((0xff & value) << 24);
    converted |= (((0xff << 8) & value) << 8);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 24) & value) >> 24);
    return converted;
}

int my_swapb(int value)
{
    int converted = 0;

    converted |= (((0xff << 24) & value) >> 24);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 8) & value) << 8);
    converted |= ((0xff & value) << 24);
    return converted;
}
