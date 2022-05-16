/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** third_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_sti(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 11;
    instruction->coding_byte = create_coding_byte(11, params + 1);
    printf("%d %d\n", instruction->instruction, get_size_from_coding_byte(instruction));
    return SUCC;
}

int check_fork(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 12;
    instruction->coding_byte = create_coding_byte(12, params + 1);
    return SUCC;
}

int check_lld(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 13;
    instruction->coding_byte = create_coding_byte(13, params + 1);
    return SUCC;
}

int check_lldi(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 14;
    instruction->coding_byte = create_coding_byte(14, params + 1);
    return SUCC;
}
