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

int lfork(struct champion *c, uint8_t *arena, struct champion *fork_param)
{
    int i = 0;
    int real_address_c = c->address + IND_SIZE + 1;
    int real_address_fork = (c->address + c->i->params[0].types.indirect)
        % MEM_SIZE;

    while (fork_param->filepath != NULL)
        ++i;
    fork_param = realloc(fork_param, sizeof(struct champion) * (i + 2));
    if (fork_param == NULL)
        return (ERR);
    fork_param[i] = *c;
    fork_param[i].address = real_address_fork;
    fork_param[i].h.prog_size = c->h.prog_size - (c->address + IND_SIZE + 1);
    copy_champion_fork(real_address_fork, real_address_c, c, arena);
    return (SUCC);
}

int aff(struct champion *c, UNUSED uint8_t *arena,
    UNUSED struct champion *fork_param)
{
    write(1, &c->registers[(c->i->params[0].types.reg - 1)], sizeof(char));
    return (SUCC);
}
