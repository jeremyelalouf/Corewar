/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** second_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_and(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 6;
    instruction->coding_byte = create_coding_byte(6, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_or(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 7;
    instruction->coding_byte = create_coding_byte(7, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_xor(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 8;
    instruction->coding_byte = create_coding_byte(8, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_zjmp(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 9;
    instruction->coding_byte = create_coding_byte(9, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_ldi(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 10;
    instruction->coding_byte = create_coding_byte(10, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}
