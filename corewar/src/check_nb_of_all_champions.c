/*
** EPITECH PROJECT, 2022
** check_nb_of_all_champions
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "my.h"
#include "virtual_machine.h"

static void compare_value_with_champions(struct champion *result, int nb_champions,
    int *value, int *index)
{
    for (int j = 0; j != nb_champions; j++) {
        if (*index == result[j].nb) {
            *value = 0;
            (*index)++;
        } else
            *value = *index;
    }
}

void found_new_nb(struct champion *result, int nb_champions,
    int *value)
{
    for (int i = 1; i <= MAX_ARGS_NUMBER && *value == 0; i++)
        compare_value_with_champions(result, nb_champions, value, &i);
}

int check_nb_of_all_champions(struct champion *result, int nb_champions,
    int *value)
{
    if (*value == 0) {
        found_new_nb(result, nb_champions, value);
        return 1;
    }
    for (int i = 0; i < (nb_champions - 1); i++) {
        if (*value == result[i].nb) {
            my_putsterr("double definition of prog_number.\n");
            return -1;
        }
    }
    return 0;
}
