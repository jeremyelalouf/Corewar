/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** first_check_functions
*/

#include "my.h"
#include "corewar.h"

static void print_byte_as_bits(char val)
{
    for (int i = 7; 0 <= i; i--)
        printf("%c\n", (val & (1 << i)) ? '1' : '0');
}

int check_live(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    int params_nbr = 0;

    instruction->instruction = 1;
    instruction->coding_byte = create_coding_byte(1, params + 1);
    if (instruction->coding_byte == FALSE)
        return ERR;
    params_nbr = get_size_from_coding_byte(instruction);
    for (int i = 0; i <= params_nbr; ++i) {
        get_parameters_size(instruction);
        printf("size = %d\n", instruction->params[i].size);
    }
    return SUCC;
}

int check_ld(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 2;
    instruction->coding_byte = create_coding_byte(2, params + 1);
    return SUCC;
}

int check_st(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 3;
    instruction->coding_byte = create_coding_byte(3, params + 1);
    return SUCC;
}

int check_add(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 4;
    instruction->coding_byte = create_coding_byte(4, params + 1);
    return SUCC;
}

int check_sub(UNUSED struct instruction *instruction, UNUSED char **params,
    UNUSED int fd)
{
    instruction->instruction = 5;
    instruction->coding_byte = create_coding_byte(5, params + 1);
    return SUCC;
}
