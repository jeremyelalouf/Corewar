/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** first_check_functions
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

int check_live(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 1;
    instruction->coding_byte = create_coding_byte(1, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_ld(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 2;
    instruction->coding_byte = create_coding_byte(2, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_st(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 3;
    instruction->coding_byte = create_coding_byte(3, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_add(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 4;
    instruction->coding_byte = create_coding_byte(4, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_sub(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 5;
    instruction->coding_byte = create_coding_byte(5, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}
