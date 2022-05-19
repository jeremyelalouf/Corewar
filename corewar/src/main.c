/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "virtual_machine.h"

int main(int argc, char const *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    if (corewar(argc, argv) == ERR)
        return EXIT_ERR;
    return 0;
}
