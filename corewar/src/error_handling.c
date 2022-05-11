/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include <stdlib.h>

#include "my.h"

void display_usages(void)
{
    my_putstr("Usage: ./yolotron-asm [source file] [output file]\n");
}

int error_handling(int ac, char const *av[])
{
    if (ac != 2)
        return -1;
    if (my_strcmp(av[1], "-h") == 0) {
        display_usages();
        exit(0);
    }
    return 0;
}
