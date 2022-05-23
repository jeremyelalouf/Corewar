/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** has_coding_byte
*/

#include <stdint.h>

int sec_has_coding_byte(uint8_t instruction)
{
    if (instruction != 1 && instruction != 9 &&
    instruction != 12 && instruction != 15)
        return 1;
    return 0;
}

int has_coding_byte(uint8_t instruction)
{
    if (instruction != 1 && instruction != 9 &&
    instruction != 12 && instruction != 15)
        return 1;
    return 0;
}
