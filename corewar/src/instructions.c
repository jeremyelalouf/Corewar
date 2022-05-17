/*
** EPITECH PROJECT, 2022
** instructions.c
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

void live(int nb)
{
    my_putstr("Le joueur ");
    my_put_nbr(nb);
    my_putstr(" est en vie.\n");
}

void ld(uint8_t *arene)
{
    printf("ld\n");
}

void st(uint8_t *arene)
{
    printf("st\n");
}

void add(int r1, int r2, int *r3)
{
    *r3 = r1 + r2;
}

void sub(int r1, int r2, int *r3)
{
    *r3 = r1 - r2;
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