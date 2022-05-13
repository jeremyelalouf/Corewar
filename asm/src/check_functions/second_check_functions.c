/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** second_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_and(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 6;
    instruction->coding_byte = create_coding_byte(6, params + 1);
    return SUCC;
}

int check_or(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 7;
    instruction->coding_byte = create_coding_byte(7, params + 1);
    return SUCC;
}

int check_xor(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 8;
    instruction->coding_byte = create_coding_byte(8, params + 1);
    return SUCC;
}

int check_zjmp(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 9;
    instruction->coding_byte = create_coding_byte(9, params + 1);
    return SUCC;
}

int check_ldi(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 10;
    instruction->coding_byte = create_coding_byte(10, params + 1);
    return SUCC;
}
