/*
** EPITECH PROJECT, 2022
** init_struct
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "../../includes/virtual_machine.h"

struct champion *init_champions(void)
{
    struct champion *result = malloc(sizeof(struct champion));

    if (result == NULL)
        return result;
    result->actual_cycle = -1;
    result->address = -1;
    result->filepath = NULL;
    result->nb = -1;
    return result;
}
