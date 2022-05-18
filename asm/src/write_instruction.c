/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write_instruction
*/

#include <stdint.h>
#include <unistd.h>

#include "corewar.h"
#include "my.h"

static const write_function_t TAB_WRITE_FUNCTION[] = {
    { REG_BYTE_SIZE, &write_register },
    { DIR_SIZE, &write_direct },
    { IND_SIZE, &write_indirect },
};

void write_register(int fd, union type *params)
{
    write(fd, &params->reg, REG_BYTE_SIZE);
}

void write_direct(int fd, union type *params)
{
    my_bswap(&params->direct, sizeof(params->direct));
    write(fd, &params->direct, DIR_SIZE);
}

void write_indirect(int fd, union type *params)
{
    my_bswap(&params->indirect, sizeof(params->indirect));
    write(fd, &params->indirect, IND_SIZE);
}

static void call_write_of_param(int fd, int j, struct instruction *instruction)
{
    for (int k = 0; k < 3; ++k) {
        if (instruction->params[j].size == TAB_WRITE_FUNCTION[k].size) {
            TAB_WRITE_FUNCTION[k].fun_ptr(fd, &instruction->params[j].types);
            return;
        }
    }
}

int write_instruction(int fd, struct instruction *instruction)
{
    int i = 0;
    int j = 0;

    write(fd, &instruction->instruction, 1);
    if (instruction->instruction != 0x01 && instruction->instruction != 0x09 &&
    instruction->instruction != 0x0c && instruction->instruction != 0x0f)
        write(fd, &instruction->coding_byte, 1);
    while (op_tab[i].code != instruction->instruction)
        ++i;
    while (j < op_tab[i].nbr_args) {
        call_write_of_param(fd, j, instruction);
        ++j;
    }
    return (0);
}
