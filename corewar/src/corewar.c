/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "../../includes/corewar.h"
#include "../../includes/my.h"
#include "../../includes/virtual_machine.h"

struct champion *get_all_champions(int ac, const char *av[], int *dump);

int corewar(int ac, const char *av[])
{
    int dump = -1;
    struct champion *champions = get_all_champions(ac, av, &dump);
    UNUSED uint8_t *arene;
    int cycle = 0;
    int i = 0;

    if (champions == NULL)
        return ERR;
    while (cycle != CYCLE_TO_DIE) {
        while (champions[i].filepath != NULL) {
            ++i;
        }
        ++cycle;
    }
    free(champions);
    return 0;
}
