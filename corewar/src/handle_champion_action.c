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

static void reset_instruction_if_error(int i, struct champion **champions)
{
    ++(*champions)[i].actual_cycle;
    ++(*champions)[i].address;
    free((*champions)[i].i);
    (*champions)[i].i = NULL;
}

static int call_instruction(struct champion *champion, uint8_t *arena,
    struct champion **champions)
{
    int tmp = champion->i->instruction;

    if (champion->actual_cycle <
        op_tab[(champion->i->instruction - 1)].nbr_cycles) {
        ++champion->actual_cycle;
        return (SUCC);
    }
    TAB_FUN_INSTRUCTION[(champion->i->instruction - 1)].fun(champion, arena,
        champions);
    if (tmp == 0x0c || tmp == 0x0f)
        return (SUCC);
    champion->actual_cycle = 0;
    champion->address += champion->address_offset + 2;
    champion->mov_in_mem += champion->address_offset + 2;
    champion->address_offset = 0;
    free(champion->i);
    champion->i = NULL;
    return (SUCC);
}

static int call_champions_instruction(int i, struct champion **champions,
    uint8_t *arena)
{
    if ((*champions)[i].i == NULL) {
        (*champions)[i].i = malloc(sizeof(struct instruction) * 1);
        if ((*champions)[i].i == NULL)
            return (ERR);
        (*champions)[i].i->instruction = arena[(*champions)[i].address];
        if ((*champions)[i].i->instruction == (uint8_t)0x00 ||
            (*champions)[i].i->instruction > (uint8_t)0x10) {
            reset_instruction_if_error(i, champions);
            return (SUCC);
        }
        (*champions)[i].address_offset =
            get_param_instruction(&(*champions)[i].address,
            (*champions)[i].i, arena);
        if ((*champions)[i].address_offset == ERR)
            reset_instruction_if_error(i, champions);
    } else {
        call_instruction(&(*champions)[i], arena, champions);
    }
    return (SUCC);
}

int handle_champion_action(struct champion **champions,
    uint8_t *arena)
{
    int i = 0;
    int nbr_dead = 0;

    while ((*champions)[i].carry != END_OF_TAB) {
        if ((*champions)[i].nbr_cycle_last_live == NBR_LIVE)
            (*champions)[i].is_dead = TRUE;
        if ((*champions)[i].is_dead == TRUE) {
            ++i;
            ++nbr_dead;
            continue;
        }
        ++(*champions)[i].nbr_cycle_last_live;
        if (call_champions_instruction(i, champions, arena) == ERR)
            return (ERR);
        ++i;
    }
    return (nbr_dead);
}

int do_game(struct champion **champions, uint8_t *arena)
{
    int cycle = 0;
    int nbr_champions = 0;
    int return_val;

    while ((*champions)[nbr_champions].carry != END_OF_TAB)
        ++nbr_champions;
    while (cycle != CYCLE_TO_DIE) {
        return_val = handle_champion_action(champions, arena);
        if (return_val == ERR)
            return (ERR);
        if (is_game_win_or_lose(nbr_champions, return_val, champions) == TRUE)
            return (SUCC);
        ++cycle;
    }
    return (SUCC);
}
