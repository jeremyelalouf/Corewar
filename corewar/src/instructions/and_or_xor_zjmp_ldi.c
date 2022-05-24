/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** and_or_xor_zjmp_ldi
*/

#include "corewar.h"
#include "virtual_machine.h"

int my_and(struct champion *c, uint8_t *arena,
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
    c->registers[(c->i->params[2].types.reg - 1)] = param1 & param2;
    c->carry = c->registers[(c->i->params[2].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}

int my_or(struct champion *c, uint8_t *arena,
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
    c->registers[(c->i->params[2].types.reg - 1)] = param1 | param2;
    c->carry = c->registers[(c->i->params[2].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}

int my_xor(struct champion *c, uint8_t *arena,
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
    c->registers[(c->i->params[2].types.reg - 1)] = param1 ^ param2;
    c->carry = c->registers[(c->i->params[2].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}

int zjmp(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion **fork_param)
{
    if (c->carry == 0)
        return (SUCC);
    c->address += c->i->params[0].types.indirect % IDX_MOD;
    return (SUCC);
}

int ldi(struct champion *c, uint8_t *arena,
    UNUSED struct champion **fork_param)
{
    int s = get_n_byte_val(IND_SIZE, (c->address +
        c->i->params[0].types.indirect % IDX_MOD), arena) + 4;

    c->registers[(c->i->params[2].types.reg - 1)] =
        get_n_byte_val(REG_SIZE, (c->address + s % IDX_MOD), arena);
    c->carry = c->registers[(c->i->params[2].types.reg - 1)] == 0 ? 0 : 1;
    return (SUCC);
}
