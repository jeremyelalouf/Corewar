/*
** EPITECH PROJECT, 2022
** handly_flag_n
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "../../includes/corewar.h"
#include "../../includes/my.h"
#include "../../includes/virtual_machine.h"

int handly_flag_n(int *index, struct champion *result, char const *av[])
{
    if (!my_str_isnum(av[*index]) || my_getnbr((char *)av[*index]) < 1
        || my_getnbr((char *)av[*index]) > MAX_ARGS_NUMBER) {
        my_putsterr("-n argument ");
        my_putsterr(av[*index]);
        my_putsterr(" is invalid.\nEnter a number between 1 and ");
        my_put_nberr(MAX_ARGS_NUMBER);
        my_putsterr(".\n");
        return -1;
    }
    result->nb = my_getnbr((char *)av[*index]);
    (*index)++;
    return 0;
}

int handly_flag_a(int *index, struct champion *result, char const *av[])
{
    if (my_strcmp(av[*index], "-a") == 0) {
        if (!my_str_isnum(av[*index + 1])) {
            my_putsterr("Invalind option.\n");
            return -1;
        }
        (*index)++;
        result->address = my_getnbr((char *)av[*index]);
        if (result->address < 0) {
            my_putsterr("-a argument ");
            my_putsterr(av[*index]);
            my_putsterr(" is invalid.\nEnter a valid memory offset.\n");
            return -1;
        }
        (*index)++;
    }
    return 0;
}

int capture_number(int *index, int ac, char const *av[], int *dump)
{
    int result = 0;

    if ((*index) + 2 > ac)
        return -1;
    (*index)++;
    if (!my_str_isnum(av[*index]) || my_strlen(av[*index]) > 15)
        return -1;
    result = my_getnbr((char *)av[*index]);
    if (result < 0)
        return -1;
    *dump = result;
    (*index)++;
    return 0;
}
