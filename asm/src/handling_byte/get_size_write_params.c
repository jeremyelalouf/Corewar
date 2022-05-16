/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** function to fill union of params and to find size of write for params
*/

#include <stdint.h>

#include "corewar.h"
#include "my.h"

static const instruction_w_index_t TAB_INSTRUCTION[] =  {
    { 1, FALSE },
    { 2, FALSE },
    { 3, FALSE },
    { 4, FALSE },
    { 5, FALSE },
    { 6, FALSE },
    { 7, FALSE },
    { 8, FALSE },
    { 9, TRUE },
    { 10, TRUE },
    { 11, TRUE },
    { 12, TRUE },
    { 13, FALSE },
    { 14, TRUE },
    { 15, TRUE },
    { 16, FALSE },
};

static int get_size_type(uint8_t type_param)
{
    if (type_param == T_REG) {
        return (REG_BYTE_SIZE);
    } else if (type_param == T_IND) {
        return (IND_SIZE);
    } else {
        return (DIR_SIZE);
    }
}

static int is_instruction_reg_or_index(int k, int *size,
    uint8_t type_param)
{
    if (TAB_INSTRUCTION[k].have_index == TRUE) {
        if (type_param != T_REG)
            *size += IND_SIZE;
        else
            *size += REG_BYTE_SIZE;
        return (TRUE);
    } else {
        return (FALSE);
    }
}

static int is_instruction_with_index(int *size, uint8_t type_param,
    struct instruction *instruction)
{
    for (int k = 0; k < NBR_OF_INSTRUCTION; ++k) {
        if (instruction->instruction == TAB_INSTRUCTION[k].instruction) {
            return (is_instruction_reg_or_index(k, size, type_param));
        }
    }
    return (FALSE);
}

int get_size_from_coding_byte(struct instruction *instruction)
{
    int i = 0;
    int j = 0;
    int size = 0;
    uint8_t type_param = 0;

    if (instruction->coding_byte == ERR_UNSIGNED)
        return ERR;
    while (op_tab[i].code != instruction->instruction)
        ++i;
    while (j < op_tab[i].nbr_args) {
        type_param = ((instruction->coding_byte << 2 * j & 0xff) >> 6);
        if (is_instruction_with_index(&size, type_param, instruction)
            == TRUE) {
            ++j;
            continue;
        }
        size += get_size_type(type_param);
        ++j;
    }
    return (size);
}
