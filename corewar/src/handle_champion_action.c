/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_champion_action
*/

#include "corewar.h"
#include "virtual_machine.h"
#include "my.h"

#include <stdlib.h>

static int call_instruction(int address_offset, struct champion *champion,
    uint8_t *arena, struct champion *champions)
{
    if (champion->actual_cycle <
        op_tab[champion->i->instruction - 1].nbr_cycles) {
        ++champion->actual_cycle;
        return (SUCC);
    }
    TAB_FUN_INSTRUCTION[champion->i->instruction - 1].fun(champion, arena,
        champions);
    champion->actual_cycle = 0;
    champion->address += address_offset + 2;
    free(champion->i);
    champion->i = NULL;
    return (SUCC);
}

static int call_champions_instruction(int i, struct champion *champions,
    uint8_t *arena)
{
    int address_offset = 0;

    if (champions[i].i == NULL) {
        champions[i].i = malloc(sizeof(struct instruction) * 1);
        if (champions[i].i == NULL)
            return (ERR);
        champions[i].i->instruction = arena[champions[i].address];
        address_offset = get_param_instruction(&champions[i].address,
            champions[i].i, arena);
        if (address_offset == ERR)
            return (ERR);
    } else {
        call_instruction(address_offset, &champions[i], arena, champions);
    }
    return (SUCC);
}

int handle_champion_action(struct champion *champions,
    uint8_t *arena)
{
    int i = 0;
    int nbr_dead = 0;

    while (champions[i].filepath != NULL) {
        if (champions[i].nbr_cycle_last_live == NBR_LIVE)
            champions[i].is_dead = TRUE;
        if (champions[i].is_dead == TRUE) {
            ++i;
            ++nbr_dead;
            continue;
        }
        ++champions->nbr_cycle_last_live;
        if (call_champions_instruction(i, champions, arena) == ERR)
            return (ERR);
        ++i;
    }
    return (nbr_dead);
}
