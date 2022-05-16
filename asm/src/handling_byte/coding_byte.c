/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** coding byte
*/

#include <stdint.h>

#include "corewar.h"
#include "my.h"

static int is_register_valid(char *reg)
{
    if (my_str_isnum(&reg[1]) && my_getnbr(&reg[1]) > 0 &&
    my_getnbr(&reg[1]) <= REG_NUMBER)
        return (TRUE);
    return (FALSE);
}

static uint8_t get_param_type(char *param)
{
    if (param[0] == 'r') {
        if (is_register_valid(param) == TRUE)
            return (T_REG);
        return (ERR_UNSIGNED);
    }
    if (param[0] == '%') {
        if (param[1] == LABEL_CHAR)
            return (T_DIR);
        if (is_size_param_valid(T_DIR, param) == TRUE)
            return (T_DIR);
        return (ERR_UNSIGNED);
    }
    if (param[0] == LABEL_CHAR)
        return (T_IND);
    if (is_size_param_valid(T_IND, param) == TRUE)
        return (T_IND);
    return ERR_UNSIGNED;
}

static int is_parameter_valid(int param_nb, int instruction,
    uint8_t *value_param)
{
    int i = 0;

    if (*value_param == 0x00)
        return (FALSE);
    while (op_tab[i].code != instruction)
        ++i;
    if ((op_tab[i].type[param_nb] & *value_param) != (*value_param & 0x07))
        return (FALSE);
    if (*value_param == T_IND)
        *value_param = VAL_IND;
    return (TRUE);
}

uint8_t create_coding_byte(int instruction, char **param)
{
    int i = 0;
    uint8_t coding_byte = 0;
    uint8_t tmp_value;

    while (param[i] != NULL) {
        tmp_value = get_param_type(param[i]);
        if (is_parameter_valid(i, instruction, &tmp_value) == TRUE)
            coding_byte |= (tmp_value << (6 - 2 * i));
        else
            return (ERR_UNSIGNED);
        ++i;
    }
    if (op_tab[instruction].nbr_args != i)
        return (ERR_UNSIGNED);
    return (coding_byte);
}
