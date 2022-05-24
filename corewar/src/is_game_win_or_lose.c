/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** is_game_win_or_lose
*/

#include "my.h"
#include "corewar.h"

int is_game_win_or_lose(int nbr_champions, int nbr_dead_champions,
    struct champion *champions)
{
    if (nbr_dead_champions == nbr_champions) {
        printf("pangolin\n");
        return (TRUE);
    }
    if (nbr_dead_champions + 1 == nbr_champions) {
        while ((*champions).is_dead != TRUE)
            ++champions;
        my_putstr("The player ");
        my_put_nbr(champions->nb);
        my_putstr("(");
        my_putstr(champions->h.prog_name);
        my_putstr(") has won.\n");
        return (TRUE);
    }
    return (FALSE);
}
