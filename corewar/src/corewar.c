/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"

struct champion *get_all_champions(int ac, const char *av[],
    int *dump, int *nb_champions);

int corewar(int ac, const char *av[])
{
    int dump = -1;
    int nb_champions = 0;
    struct champion *champions = get_all_champions(ac, av, &dump, &nb_champions);
    UNUSED uint8_t *arene;
    int cycle = 0;
    int i = 0;

    if (champions == NULL)
        return ERR;
    while (cycle != CYCLE_TO_DIE) {
        while (i < nb_champions) {
            ++i;
        }
        ++cycle;
    }
    free(champions);
    return 0;
}
