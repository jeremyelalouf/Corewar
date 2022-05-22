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

int game(int nb_champions, struct champion* champions, UNUSED uint8_t *arene)
{
    int cycle = 0;
    int i = 0;

    while (cycle != CYCLE_TO_DIE) {
        while (i < nb_champions) {
            printf("name : %s\nadress : %d\nnb : %d\n---\n", champions[i].h.prog_name, champions[i].address, champions[i].nb);
            ++i;
        }
        ++cycle;
    }
    return 0;
}

int corewar(int ac, const char *av[])
{
    int dump = -1;
    int nb_champions = 0;
    struct champion *champions =
        get_all_champions(ac, av, &dump, &nb_champions);
    UNUSED uint8_t *arene = NULL;

    if (champions == NULL) {
        free(champions);
        return ERR;
    }
    if (nb_champions < 2) {
        my_putstr("Usage: ./corewar [-dump nbr_cycle]");
        my_putstr(" [[-n prog_number] [-a load_address] prog_name] ...");
        return ERR;
    }
    if (game(nb_champions, champions, arene) == -1)
        return ERR;
    free(champions);
    return SUCC;
}
