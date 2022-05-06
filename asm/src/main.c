/*
** EPITECH PROJECT, 2022
** starter
** File description:
** main
*/

#include "my.h"
#include "op.h"
#include "corewar.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

int bswap(int value)
{
    int converted = 0;

    converted |= ((0xff & value) << 24);
    converted |= (((0xff << 8) & value) << 8);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 24) & value) >> 24);
    return converted;
}

int compile(char *av[])
{
    return SUCC;
}

int main(int argc, char *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    compile(argv);
    return SUCC;
}
