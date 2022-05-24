/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_size_type
*/

#include "corewar.h"

int get_size_type(uint8_t type_param)
{
    if (type_param == T_REG) {
        return (REG_BYTE_SIZE);
    } else if (type_param == T_IND) {
        return (IND_SIZE);
    } else {
        return (DIR_SIZE);
    }
}
