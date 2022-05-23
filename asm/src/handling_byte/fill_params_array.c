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
    uint8_t param_type = ((instruction->coding_byte << (2 * index_param)
        & 0xff) >> 6);

    return (is_instruction_reg_or_index((int)instruction->instruction - 1,
        param_type));
}

static void fill_index(char **params, struct instruction *instruction, int i)
{
    if (params[i][0] == DIRECT_CHAR || params[i][0] == 'r')
        instruction->params[i].types.indirect = my_getnbr((params[i]) + 1);
    else if (params[i][1] == LABEL_CHAR)
        instruction->params[i].types.indirect = my_getnbr((params[i]) + 2);
    else
        instruction->params[i].types.indirect = my_getnbr((params[i]));
}

int fill_params_array(struct instruction *instruction, char **params)
{
    int params_nbr = get_parameters_size(instruction);

    for (int i = 0; i != params_nbr; ++i) {
        if (is_param_index(i, instruction) == TRUE) {
            fill_index(params, instruction, i);
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
