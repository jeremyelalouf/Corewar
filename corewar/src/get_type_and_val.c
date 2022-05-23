/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_typa_and_val
*/

#include "corewar.h"

uint32_t get_n_byte_val(int n, int address, uint8_t *arena)
{
    int i = 1;
    int real_address = address % MEM_SIZE;
    uint32_t val = 0;

    while (i <= n) {
        val = arena[real_address] << (24 / i) & 0xff;
        ++i;
        ++real_address;
        if (real_address >= MEM_SIZE)
            real_address = 0;
    }
    return (val);
}

uint8_t get_type_param(int param_pos, uint8_t coding_byte)
{
    uint8_t return_val = 0;

    return_val = ((coding_byte << (2 * param_pos) & 0xff) >> 6);
    return (return_val);
}

uint32_t get_reg_val(int p_nb, struct champion *c, UNUSED uint8_t *arena)
{
    return (c->registers[(c->i->params[p_nb].types.reg - 1)]);
}

uint32_t get_ind_val(int p_nb, struct champion *c, uint8_t *arena)
{
    return (get_n_byte_val(VAL_IND, c->i->params[p_nb].types.indirect, arena));
}

uint32_t get_dir_val(int p_nb, struct champion *c, UNUSED uint8_t *arena)
{
    return (c->i->params[p_nb].types.direct);
}
