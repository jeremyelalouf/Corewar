/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** fill_size_param
*/

#include <stdint.h>

#include "corewar.h"
#include "my.h"

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

static int is_instruction_reg_or_index(int k, uint8_t type_param,
    struct arg *args)
{
    if (TAB_INSTRUCTION[k].have_index == TRUE) {
        if (type_param != T_REG)
            args->size = IND_SIZE;
        else
            args->size = REG_BYTE_SIZE;
        return (TRUE);
    } else {
        return (FALSE);
    }
}

static int is_instruction_with_index(int j, uint8_t type_param,
    struct instruction *instruction)
{
    for (int k = 0; k < NBR_OF_INSTRUCTION; ++k) {
        if (instruction->instruction == TAB_INSTRUCTION[k].instruction) {
            return (is_instruction_reg_or_index(k, type_param,
                &instruction->params[j]));
        }
    }
    return (FALSE);
}

int get_parameters_size(struct instruction *instruction)
{
    int i = 0;
    uint8_t type_param = 0;

    while (i < op_tab[instruction->instruction - 1].nbr_args) {
        type_param = ((instruction->coding_byte << 2 * i & 0xff) >> 6);
        if (is_instruction_with_index(i, type_param, instruction)
            == TRUE) {
            ++i;
            continue;
        }
        instruction->params[i].size = get_size_type(type_param);
        ++i;
    }
    return (i);
}
