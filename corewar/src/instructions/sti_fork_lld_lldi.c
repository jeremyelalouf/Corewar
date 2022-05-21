/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** sti_fork_lld_lldi
*/

#include "corewar.h"
#include "virtual_machine.h"

#include <stdlib.h>

static void copy_reg_size_val(int address, uint32_t val, uint8_t *arena)
{
    int i = 0;
    int j = 1;
    int real_address = address % MEM_SIZE;

    while (i < REG_SIZE) {
        arena[real_address] = (val << (24 / j) & 0xff) >> (24 / j);
        ++i;
        ++j;
        ++real_address;
        if (real_address >= MEM_SIZE)
            real_address = 0;
    }
}

void sti(struct champion *c, uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    int param1 = 0;
    int param2 = 0;

    for (int i = 0; i < 3; ++i) {
        if (get_type_param(0, c->i->coding_byte) == TAB_GET_VALUE[i].type) {
            param1 = TAB_GET_VALUE[i].fun(0, c, arena);
            break;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (get_type_param(1, c->i->coding_byte) == TAB_GET_VALUE[i].type) {
            param2 = TAB_GET_VALUE[i].fun(1, c, arena);
            break;
        }
    }
    copy_reg_size_val((c->address + (param1 + param2) % IDX_MOD),
        c->registers[(c->i->params[0].types.reg - 1)], arena);
}

void my_fork(struct champion *c, uint8_t *arena, struct champion *fork_param)
{
    int i = 0;
    int real_address_c = c->address + IND_SIZE + 1;
    int real_address_fork = (c->address + c->i->params[0].types.indirect %
        IDX_MOD) % MEM_SIZE;

    while (fork_param->filepath != NULL)
        ++i;
    fork_param = realloc(fork_param, i + 2);
    fork_param[i] = *c;
    fork_param[i].address = real_address_fork;
    fork_param[i].h.prog_size = c->h.prog_size - (c->address + IND_SIZE + 1);
    for (int j = 0; j < (c->h.prog_size - (c->address + IND_SIZE + 1)); ++j) {
        arena[real_address_fork] = arena[real_address_c];
        ++real_address_c;
        ++real_address_fork;
        if (real_address_c >= MEM_SIZE)
            real_address_c = 0;
        if (real_address_fork >= MEM_SIZE)
            real_address_fork = 0;
    }
}

void lld(struct champion *c, uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    c->registers[(c->i->params[1].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + c->i->params[0].types.direct),
        arena);

    if (c->registers[(c->i->params[1].types.reg - 1)] == 0)
        c->carry = 0;
    else
        c->carry = 1;}

void lldi(struct champion *c, uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    int s = get_n_byte_val(IND_SIZE, (c->address +
        c->i->params[0].types.indirect), arena) + 4;

    c->registers[(c->i->params[2].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + s), arena);
    if (c->registers[(c->i->params[2].types.reg - 1)] == 0)
        c->carry = 0;
    else
        c->carry = 1;
}
