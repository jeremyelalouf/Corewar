/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** lfork_aff
*/

#include "corewar.h"
#include "my.h"

#include <stdlib.h>
#include <unistd.h>

void copy_champion_fork(int real_address_fork, int real_address_c,
    struct champion *c, uint8_t *arena)
{
    for (int j = 0; j < (c->h.prog_size - (c->mov_in_mem)); ++j) {
        arena[real_address_fork] = arena[real_address_c];
        ++real_address_c;
        ++real_address_fork;
        if (real_address_c >= MEM_SIZE)
            real_address_c = 0;
        if (real_address_fork >= MEM_SIZE)
            real_address_fork = 0;
    }
}

void reset_champion_after_fork(struct champion *champion)
{
    champion->actual_cycle = 0;
    champion->address += 3;
    champion->mov_in_mem += 3;
    champion->address_offset = 0;
    free(champion->i);
    champion->i = NULL;
}

void dup_fork_param(struct champion *fork_param1,
    struct champion *fork_param2)
{
    fork_param1->carry = fork_param2->carry;
    fork_param1->is_dead = fork_param2->is_dead;
    fork_param1->nbr_cycle_last_live = fork_param2->nbr_cycle_last_live;
    fork_param1->actual_cycle = fork_param2->actual_cycle;
    fork_param1->i = NULL;
    for (int i = 0; i < REG_NUMBER; ++i)
        fork_param1->registers[i] = fork_param2->registers[i];
    fork_param1->nb = fork_param2->nb;
    fork_param1->nb = 0;
    fork_param1->h.magic = fork_param2->h.magic;
    my_strcpy(fork_param1->h.prog_name, fork_param2->h.prog_name);
    my_strcpy(fork_param1->h.comment, fork_param2->h.comment);
    fork_param1->h.prog_size = fork_param2->h.prog_size;
    fork_param1->mov_in_mem = 0;
    reset_champion_after_fork(fork_param2);
}

int lfork(struct champion *c, uint8_t *arena, struct champion **fork_param)
{
    int i = 0;
    int j = 0;
    int c_nb = c->nb;
    int real_address_c = c->address + IND_SIZE + 1;
    int real_address_fork = (c->address + c->i->params[0].types.indirect)
        % MEM_SIZE;

    while ((*fork_param)[i].carry != END_OF_TAB)
        ++i;
    *fork_param = realloc(*fork_param, sizeof(struct champion) * (i + 2));
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

int aff(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion **fork_param)
{
    write(1, &c->registers[(c->i->params[0].types.reg - 1)], sizeof(char));
    return (SUCC);
}
