/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** fourth_check_functions
*/

#include "my.h"
#include "corewar.h"

int check_lfork(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 15;
    instruction->coding_byte = create_coding_byte(15, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}

int check_aff(struct instruction *instruction, char **params, int fd)
{
    instruction->instruction = 16;
    instruction->coding_byte = create_coding_byte(16, params);
    if (instruction->coding_byte == FALSE)
        return ERR;
    fill_params_array(instruction, params);
    write_instruction(fd, instruction);
    return SUCC;
}
