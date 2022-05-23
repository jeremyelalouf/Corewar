/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"
#include "check_options.h"

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

int create_new_champion(struct vm_i *vm_inf, struct opt_value *tmp)
{
    vm_inf->champions = realloc(vm_inf->champions, sizeof(struct champion) *
        (vm_inf->champions_nbr + 1));
    if (vm_inf->champions == NULL)
        return ERR;
    vm_inf->champions[vm_inf->champions_nbr].actual_cycle = 0;
    if (vm_inf->champions_nbr > 1 && tmp->next_champion_address <=
        vm_inf->champions[vm_inf->champions_nbr].address)
        return ERR;
    vm_inf->champions[vm_inf->champions_nbr].address =
        tmp->next_champion_address;
    if (tmp->next_champion_nbr != 0)
        vm_inf->champions[vm_inf->champions_nbr].nb = tmp->next_champion_nbr;
    else
        vm_inf->champions[vm_inf->champions_nbr].nb =
            vm_inf->champions_nbr + 1;
    return SUCC;
}

int fill_arene_and_i(struct vm_i *vm_inf, uint8_t *arene, char *path_to_file,
    struct opt_value *tmp)
{
    int fd = open(path_to_file, O_RDONLY);
    int address = 0;
    header_t header_tmp;

    if (read(fd, &header_tmp, sizeof(header_t)) == ERR)
        return ERR;
    my_bswap(&header_tmp.magic, sizeof(int));
    if (header_tmp.magic != COREWAR_EXEC_MAGIC) {
        close(fd);
        return ERR;
    }
    if (create_new_champion(vm_inf, tmp) == ERR)
        return ERR;
    address = vm_inf->champions[vm_inf->champions_nbr].address;
    my_bswap(&header_tmp.prog_size, sizeof(int));
    read(fd, arene + address, header_tmp.prog_size);
    tmp->next_champion_address = address + header_tmp.prog_size + 1;
    ++vm_inf->champions_nbr;
    close(fd);
    return SUCC;
}

int handle_opt_and_fill_arene(struct vm_i *vm_inf, uint8_t *arene, char *av[])
{
    int return_value = 0;
    struct opt_value tmp = {
        .next_champion_address = 0,
        .next_champion_nbr = 0,
    };

    vm_inf->dump = -1;
    for (int i = 1; av[i] != NULL; ++i) {
        if (av[i][0] == '-')
            return_value = handle_option(vm_inf, av, &i, &tmp);
        if (return_value == ERR)
            return ERR;
        if (fill_arene_and_i(vm_inf, arene, av[i], &tmp) == ERR)
            return ERR;
        if (vm_inf->champions_nbr > MAX_ARGS_NUMBER)
            return ERR;
    }
    return SUCC;
}

int corewar(int ac, char *av[])
{
    struct vm_i vm_inf = {.champions = NULL};
    uint8_t *arene = malloc(sizeof(uint8_t) * MEM_SIZE);

    if (arene == NULL)
        return NULL;
    my_memset(arene, 0, MEM_SIZE);
    if (handle_opt_and_fill_arene(&vm_inf, arene, av) == ERR)
        return ERR;
    return SUCC;
}
