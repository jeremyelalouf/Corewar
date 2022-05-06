/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include "my.h"

#include <stdlib.h>

static void print_help(void)
{
    my_putstr("USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\
        file_name file in assembly language to be converted \
into file_name.cor,\nan executable in the Virtual Machine.\n");
    exit(SUCC);
}

int error_handling(int ac, char *av[])
{
    if (ac < 2) {
        my_putsterr("Please give a *.s file as a parameter.\n");
        return ERR;
    }
    if (my_strcmp(av[1], "-h") == 0)
        print_help();
    return SUCC;
}
