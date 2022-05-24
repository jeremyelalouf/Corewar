/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_instruction
*/

#include <stdlib.h>

#include "corewar.h"
#include "virtual_machine.h"
#include "my.h"

#include <stdlib.h>

static uint32_t get_param(int param_size, uint8_t *arena)
{
    int i = 0;
    uint32_t param = 0;

    my_bswap(arena, param_size);
    if (param_size == 1) {
        if (arena[0] > REG_NUMBER || arena[0] == 0)
            return (ERR);
    }
    while (i < param_size) {
        param |= arena[i] << (8 * i);
        ++i;
    }
    return (param);
}

static int is_instruction_reg_or_index(int k, uint8_t type_param,
    int *param_size)
{
    if (TAB_INSTRUCTION[k].have_index == TRUE) {
        if (type_param != T_REG)
           *param_size = IND_SIZE;
        else
            *param_size = REG_BYTE_SIZE;
        return (TRUE);
    } else {
        return (FALSE);
    }
}

static int *get_read_size(uint8_t instruction, uint8_t coding_byte)
{
    int i = 0;
    uint8_t type_param = 0;
    int *param_size = malloc(sizeof(int) * 4);

    if (param_size == NULL)
        return NULL;
    while (i < op_tab[(instruction - 1)].nbr_args) {
        type_param = ((coding_byte << (2 * i) & 0xff) >> 6);
        if (is_instruction_reg_or_index((int)(instruction - 1), type_param,
            &param_size[i])) {
            ++i;
            continue;
        }
        param_size[i] = get_size_type(type_param);
        ++i;
    }
    if (i != 4)
        param_size[i] = END_OF_TAB;
    return param_size;
}

static int get_param_from_coding_byte(int *pos_in_arena,
    struct instruction *instruction, uint8_t *arena)
{
    int size = 0;
    int *param_size;

    instruction->coding_byte = arena[(*pos_in_arena + 1)];
    if (verify_coding_byte(instruction) == ERR)
        return (ERR);
    param_size = get_read_size(instruction->instruction,
        instruction->coding_byte);
    if (param_size == NULL)
        return (ERR);
    for (int i = 0; param_size[i] != END_OF_TAB && i < 4; ++i) {
        instruction->params[i].types.direct = get_param(param_size[i],
            &arena[(*pos_in_arena + size + 2)]);
        if (instruction->params[i].types.direct == ERR)
            return (ERR);
        size += param_size[i];
    }
    free(param_size);
    return (size);
}

int get_param_instruction(int *i, struct instruction *instruction,
    uint8_t *arena)
{
    int r_val = 0;

    if (instruction->instruction == (uint8_t)0x01) {
        instruction->params[0].types.direct = get_param(DIR_SIZE,
            &arena[(*i + 1)]);
        r_val += 3;
    } else if (instruction->instruction == (uint8_t)0x09 ||
        instruction->instruction == (uint8_t)0x0c ||
        instruction->instruction == (uint8_t)0x0f) {
        instruction->params[0].types.indirect = get_param(IND_SIZE,
            &arena[(*i + 1)]);
        r_val += 1;
    } else {
        r_val = get_param_from_coding_byte(i, instruction, arena);
    }
    return (r_val);
}
