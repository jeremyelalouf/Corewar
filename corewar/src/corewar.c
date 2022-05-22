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

int game(int nb_champions, struct champion* champions, uint8_t *arena)
{
    int cycle = 0;
    int nbr_champions = 0;
    int return_val;

    while (champions[nbr_champions].filepath != NULL)
        ++nbr_champions;
    while (cycle != CYCLE_TO_DIE) {
        return_val = handle_champion_action(champions, arena);
        if (return_val == ERR)
            return (ERR);
        if (is_game_win_or_lose(nbr_champions, return_val, champions) == TRUE)
            return (SUCC);
        ++cycle;
    }
    return (SUCC);
}

uint8_t *fill_arena(struct champion *champions)
{
    uint8_t *arena = malloc(sizeof(uint8_t) * MEM_SIZE);

    if (arena == NULL)
        return (NULL);
    return (arena);
}

int corewar(int ac, const char *av[])
{
    int dump = -1;
    int nb_champions = 0;
    struct champion *champions =
        get_all_champions(ac, av, &dump, &nb_champions);
    uint8_t *arena = NULL;

    if (champions == NULL)
        return ERR;
    if (nb_champions < 2) {
        my_putstr("Usage: ./corewar [-dump nbr_cycle]");
        my_putstr(" [[-n prog_number] [-a load_address] prog_name] ...");
        return ERR;
    }
    if (game(nb_champions, champions, arena) == -1)
        return ERR;
    free(champions);
    return SUCC;
}
