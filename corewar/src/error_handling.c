/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include <stdlib.h>

#include "my.h"
#include "virtual_machine.h"

int handly_error_nb_champions(int nb_champions)
{
    if (nb_champions > MAX_ARGS_NUMBER) {
        my_putsterr("The number of champion load is above the limit.\n");
        return -1;
    }
    return 0;
}

void display_usages(void)
{
    my_putstr("\nUSAGE\n\n./corewar [-dump nbr_cycle]");
    my_putstr(" [[-n prog_number] [-a load_address] prog_name] ...\n\n");
    my_putstr("DESCRIPTION\n\n- dump nbr_cycle dumps the memmory");
    my_putstr(" after the nbr_cycle execution (if the round isn't\n");
    my_putstr("  already over) with the following format: 32 bytes/line\n");
    my_putstr("  in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("- n prog_number sets the next program's number. By default,");
    my_putstr(" the first free number\n  in the parameter order\n");
    my_putstr("- a load_address sets the next program’s loading address. ");
    my_putstr("When no address is\n  specified, ");
    my_putstr(" optimize the addresses so that ");
    my_putstr("the processes are as far\n  away from each other as possible.");
    my_putstr(" The addresses are MEM_SIZE modulo.\n");
}

int error_handling(int ac, char const *av[])
{
    if (ac == 1) {
        my_putstr("Usage: ./corewar [-dump nbr_cycle]");
        my_putstr(" [[-n prog_number] [-a load_address] prog_name] ...");
        exit(1);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        display_usages();
        exit(0);
    }
    return 0;
}
