/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"

int fill_champion(struct champion *result, int champions_nbr,
    int *index, const char *av[])
{
    result->filepath = av[*index];
    int fd = open(result->filepath, O_RDONLY);
    UNUSED int little = 0;

    if (fd == -1)
        return -1;
    if (read(fd, &result[champions_nbr - 1].h, sizeof(header_t)) == -1)
        return -1;
    // if (my_swapb(header.magic) != COREWAR_EXEC_MAGIC)
    //     return -1;
    // little = my_bswap(header.prog_size);
    //     return -1;
    *index += 1;
    close(fd);
    return 0;
}

struct champion *get_all_champions(int ac, const char *av[])
{
    struct champion *result = NULL;
    int champions_nbr = 0;
    int i = 1;

    while (i < ac) {
        ++champions_nbr;
        result = realloc(result, sizeof(struct champion) * champions_nbr);
        if (result == NULL)
            return NULL;
        if (my_strcmp(av[i], "-dump") == 0)
            i += 2;
        if (handle_flags(result + (champions_nbr - 1), (char **)av, &i) == ERR)
            return NULL;
        else
            if (fill_champion(result, champions_nbr, &i, av) == ERR)
                return NULL;
    }
    return result;
}

int corewar(int ac, const char *av[])
{
    int cycle = 0;
    int i = 0;
    struct champion *champions = get_all_champions(ac, av);
    UNUSED uint8_t *arene;
    
    if (champions == NULL)
        return ERR;
    // printf("--\n%s\nnb = %i\naddress = %i\n--\n", champions->h.prog_name, champions->nb, champions->address);
    // printf("%s\nnb = %i\naddress = %i\n--\n", champions[1].h.prog_name, champions[1].nb, champions[1].address);
    while (cycle != CYCLE_TO_DIE) {
        while (champions[i].filepath != NULL) {
            ++i;
        }
        ++cycle;
    }
    return 0;
}