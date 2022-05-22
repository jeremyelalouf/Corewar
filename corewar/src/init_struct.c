/*
** EPITECH PROJECT, 2022
** init_struct
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "virtual_machine.h"

struct champion *init_champions(struct champion *result)
{
    result->actual_cycle = 0;
    result->address = 0;
    result->filepath = NULL;
    result->nb = 0;
    return result;
}
