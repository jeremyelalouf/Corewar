/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** fourth_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_lfork(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 15;
    instruction->coding_byte = create_coding_byte(15, params + 1);
    return SUCC;
}

int check_aff(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 16;
    instruction->coding_byte = create_coding_byte(16, params + 1);
    return SUCC;
}
