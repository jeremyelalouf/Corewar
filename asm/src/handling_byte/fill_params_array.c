/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** fill_params_array
*/

#include "my.h"
#include "corewar.h"
#include "op.h"

static int is_instruction_reg_or_index(int i, uint8_t param_type)
{
    if (TAB_INSTRUCTION[i].have_index == TRUE) {
        if (param_type != T_REG)
            return (TRUE);
        return (FALSE);
    }
    return (FALSE);
}

static int is_param_index(int index_param, struct instruction *instruction)
{
    uint8_t param_type = ((instruction->coding_byte << 2 * index_param & 0xff)
        >> 6);

    for (int i = 0; i < NBR_OF_INSTRUCTION; ++i) {
        if (instruction->instruction == TAB_INSTRUCTION[i].instruction) {
            return (is_instruction_reg_or_index(i, param_type));
        }
    }
    return (FALSE);
}

int fill_params_array(struct instruction *instruction, char **params)
{
    int params_nbr = get_parameters_size(instruction);

    for (int i = 0; i != params_nbr; ++i) {
        if (is_param_index(i, instruction) == TRUE) {
            instruction->params[i].types.indirect = 0;
            continue;
        }
        if (instruction->params[i].size == IND_SIZE)
            instruction->params[i].types.indirect = my_getnbr((params[i]));
        if (instruction->params[i].size == DIR_SIZE)
            instruction->params[i].types.direct = my_getnbr((params[i]) + 1);
        if (instruction->params[i].size == REG_BYTE_SIZE)
            instruction->params[i].types.reg = my_getnbr((params[i]) + 1);
    }
    return SUCC;
}
