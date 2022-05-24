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

int sti(struct champion *c, uint8_t *arena,
    UNUSED struct champion **fork_param)
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
    return (SUCC);
}

int my_fork(struct champion *c, uint8_t *arena, struct champion **fork_param)
{
    int i = 0;
    int j = 0;
    int c_nb = c->nb;
    int real_address_c = c->address + IND_SIZE + 1;
    int real_address_fork = (c->address + c->i->params[0].types.indirect %
        IDX_MOD) % MEM_SIZE;

    while ((*fork_param)[i].carry != END_OF_TAB)
        ++i;
    (*fork_param) = realloc((*fork_param), sizeof(struct champion) * (i + 2));
    if (*fork_param == NULL)
        return (ERR);
    while ((*fork_param)[j].nb != c_nb)
        ++j;
    dup_fork_param(&(*fork_param)[i], &(*fork_param)[j]);
    (*fork_param)[i].address = real_address_fork;
    copy_champion_fork(real_address_fork, real_address_c, &(*fork_param)[i],
        arena);
    (*fork_param)[i].carry = END_OF_TAB;
    return (SUCC);
}

int lld(struct champion *c, uint8_t *arena,
    UNUSED struct champion **fork_param)
{
    c->registers[(c->i->params[1].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + c->i->params[0].types.direct),
        arena);

    c->carry = c->registers[(c->i->params[1].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}

int lldi(struct champion *c, uint8_t *arena,
    UNUSED struct champion **fork_param)
{
    int s = get_n_byte_val(IND_SIZE, (c->address +
        c->i->params[0].types.indirect), arena) + 4;

    c->registers[(c->i->params[2].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + s), arena);
    c->carry = c->registers[(c->i->params[2].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}
