/*
** EPITECH PROJECT, 2022
** instructions
** File description:
** instructions
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "op.h"
#include "corewar.h"
#include "virtual_machine.h"

void live(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    my_putstr("Le joueur ");
    my_put_nbr(c->nb);
    my_putstr(" (");
    my_putstr(c->h.prog_name);
    my_putstr(") est en vie.\n");
}

void ld(struct champion *c, uint8_t *arena, UNUSED struct champion *fork_param)
{
    c->registers[(c->i->params[1].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + c->i->params[0].types.direct %
        IDX_MOD), arena);

    if (c->registers[(c->i->params[1].types.reg - 1)] == 0)
        c->carry = 0;
    else
        c->carry = 1;
}

void my_st(struct champion *c, uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    int real_address;

    if (get_type_param(1, c->i->coding_byte) == T_REG) {
        c->registers[(c->i->params[1].types.reg - 1)] =
            c->registers[(c->i->params[0].types.reg - 1)];
        return;
    }
    if (get_type_param(1, c->i->coding_byte) == VAL_IND)
        real_address = (c->address + c->i->params[1].types.indirect % IDX_MOD)
            % MEM_SIZE;
    else
        real_address = c->i->params[1].types.direct;
    for (int i = 0; i < REG_SIZE; ++i) {
        arena[real_address] = c->registers[(c->i->params[0].types.reg - 1)] <<
            (24 / i) & 0xff;
        ++real_address;
        if (real_address >= MEM_SIZE)
            real_address = 0;
    }
}

void add(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    c->registers[(c->i->params[2].types.reg - 1)] =
        c->registers[(c->i->params[1].types.reg - 1)] +
        c->registers[(c->i->params[0].types.reg - 1)];
    if (c->registers[(c->i->params[2].types.reg - 1)] == 0)
        c->carry = 0;
    else
        c->carry = 1;
}

void sub(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    c->registers[(c->i->params[2].types.reg - 1)] =
        c->registers[(c->i->params[1].types.reg - 1)] -
        c->registers[(c->i->params[0].types.reg - 1)];
    if (c->registers[(c->i->params[2].types.reg - 1)] == 0)
        c->carry = 0;
    else
        c->carry = 1;
}
