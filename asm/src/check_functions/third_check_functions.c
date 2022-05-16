/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** third_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_sti(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 11;
    instruction->coding_byte = create_coding_byte(11, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_fork(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 12;
    instruction->coding_byte = create_coding_byte(12, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    return SUCC;
}

int check_lld(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 13;
    instruction->coding_byte = create_coding_byte(13, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    return SUCC;
}

int check_lldi(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 14;
    instruction->coding_byte = create_coding_byte(14, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    return SUCC;
}
