/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include <stdlib.h>

#include "../../includes/my.h"
#include "../../includes/virtual_machine.h"

int check_nb_of_all_champions(struct champion *result, int nb_champions,
    int value)
{
    for (int i = 0; i < (nb_champions - 1); i++) {
        if (value == result[i].nb) {
            my_putsterr("double definition of prog_number.\n");
            return -1;
        }
    }
    return 0;
}

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
    my_putstr("Usage: ./yolotron-asm [source file] [output file]\n");
}

int error_handling(UNUSED int ac, char const *av[])
{
    if (my_strcmp(av[1], "-h") == 0) {
        display_usages();
        exit(0);
    }
    return 0;
}
