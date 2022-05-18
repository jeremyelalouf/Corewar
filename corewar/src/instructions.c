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

void live(int nb, char const *name)
{
    my_putstr("Le joueur ");
    my_put_nbr(nb);
    my_putstr(" (");
    my_putstr(name);
    my_putstr(") est en vie.\n");
}

void ld(int nb, int *rx, uint8_t *pc)
{
    *rx = pc + nb % IDX_MOD;
}

void st(int *nb1, int *nb2, uint8_t *pc, uint8_t coding_byte)
{
    
    // if les deux sont des r, r1 dans r2
    // sinon pc + nb % IDX_MOD = *rx;
    printf("st\n");
}

int add(struct instruction * const i, uint8_t *arene)
{
    arene[(i->params[2].types.reg - 1) * REG_SIZE] =
        arene[(i->params[1].types.reg - 1) * REG_SIZE]
        + arene[(i->params[0].types.reg - 1) * REG_SIZE];
}

void sub(struct instruction * const i, uint8_t *arene)
{
    arene[(i->params[2].types.reg - 1) * REG_SIZE] =
        arene[(i->params[1].types.reg - 1) * REG_SIZE]
        - arene[(i->params[0].types.reg - 1) * REG_SIZE];
}

void and(uint8_t *arene)
{
    printf("and\n");
}

void or(uint8_t *arene)
{
    printf("or\n");
}

void xor(uint8_t *arene)
{
    printf("xor\n");
}

void zjmp(uint8_t *arene)
{
    printf("zjmp\n");
}

void ldi(uint8_t *arene)
{
    printf("ldi\n");
}

void sti(uint8_t *arene)
{
    printf("sti\n");
}

void my_fork(uint8_t *arene)
{
    printf("lfork\n");
}

void lld(uint8_t *arene)
{
    printf("lld\n");
}

void lldi(uint8_t *arene)
{
    printf("lldi\n");
}

void lfork(uint8_t *arene)
{
    printf("lfork\n");
}

void aff(uint8_t *arene)
{
    printf("aff\n");
}