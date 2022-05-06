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
