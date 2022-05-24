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
    printf("call i\n");
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

    //printf("wtf\n");
    if (champions[i].i == NULL) {
        //printf("toto\n");
        champions[i].i = malloc(sizeof(struct instruction) * 1);
        if (champions[i].i == NULL)
            return (ERR);
        champions[i].i->instruction = arena[champions[i].address];
        address_offset = get_param_instruction(&champions[i].address,
            champions[i].i, arena);
        if (address_offset == ERR) {
            printf("uhmu\n");
            return (ERR);
        }
    } else {
        //printf("tototo\n");
        call_instruction(address_offset, &champions[i], arena, champions);
    }
    return (SUCC);
}

int handle_champion_action(struct champion *champions,
    uint8_t *arena)
{
    int i = 0;
    int nbr_dead = 0;

    while (champions[i].carry != END_OF_TAB) {
        if (champions[i].nbr_cycle_last_live == NBR_LIVE)
            champions[i].is_dead = TRUE;
        if (champions[i].is_dead == TRUE) {
            printf("??3\n");
            ++i;
            ++nbr_dead;
            continue;
        }
        ++champions[i].nbr_cycle_last_live;
        if (call_champions_instruction(i, champions, arena) == ERR)
            return (ERR);
        ++i;
    }
    return (nbr_dead);
}

int do_game(struct champion *champions, uint8_t *arena)
{
    int cycle = 0;
    int nbr_champions = 0;
    int return_val;

    while (champions[nbr_champions].carry != END_OF_TAB)
        ++nbr_champions;
    while (cycle != CYCLE_TO_DIE) {
        return_val = handle_champion_action(champions, arena);
        if (return_val == ERR)
            return (ERR);
        if (is_game_win_or_lose(nbr_champions, return_val, champions) == TRUE) {
            printf("walibi\n");
            return (SUCC);
        }
        ++cycle;
    }
    return (SUCC);
}
