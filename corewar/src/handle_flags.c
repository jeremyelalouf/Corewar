/*
** EPITECH PROJECT, 2022
** handle_flags
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"

void handle_n_flag(struct champion *c, int value)
{
    c->nb = value;
}

void handle_a_flag(struct champion *c, int value)
{
    c->address = value;
}

static const struct handle_flags FLAGS[] = {
    {.flag = "-n", .func = &handle_n_flag},
    {.flag = "-a", .func = &handle_a_flag},
};

int handle_flags(struct champion *result, char **av, int *index)
{
    if (av[*index][0] != '-') {
        result->address = 0;
        result->nb = 0;
        return 1;
    }
    for (int i = 0; i != FLAGS_NUMBER; ++i) {
        if (my_strcmp(av[*index], FLAGS[i].flag) == 0) {
            FLAGS[i].func (result, my_getnbr(av[*index + 1]));
            *index += 2;
            return SUCC;
        }
    }
    return ERR;
}
