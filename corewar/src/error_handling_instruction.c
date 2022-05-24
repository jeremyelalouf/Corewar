/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** error_handling_instruction
*/

#include "corewar.h"
#include "my.h"

int verify_coding_byte(struct instruction *instruction)
{
    uint8_t type_param = 0;

    for (int i = 0; i < op_tab[(instruction->instruction - 1)].nbr_args; ++i) {
        type_param = ((instruction->coding_byte << (2 * i) & 0xff) >> 6);
        if ((op_tab[(instruction->instruction - 1)].type[i] & type_param) !=
            (type_param & 0x07))
            return (ERR);
    }
    return (SUCC);
}
