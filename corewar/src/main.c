/*
** EPITECH PROJECT, 2022
** starter
** File description:
** main
*/

#include "my.h"
#include "corewar.h"

int main(int argc, char *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    return SUCC;
}
