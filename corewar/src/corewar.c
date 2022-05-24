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

static void init_info_champion(header_t *header, struct vm_i *vm_inf)
{
    for (int i = 0; i < REG_NUMBER; ++i) {
        vm_inf->champions[vm_inf->champions_nbr].registers[i] = 0;
    }
    vm_inf->champions[vm_inf->champions_nbr].is_dead = FALSE;
    vm_inf->champions[vm_inf->champions_nbr].nbr_cycle_last_live = 0;
    vm_inf->champions[vm_inf->champions_nbr].carry = 0;
    vm_inf->champions[vm_inf->champions_nbr].i = NULL;
    my_strcpy(vm_inf->champions[vm_inf->champions_nbr].h.prog_name,
        header->prog_name);
    vm_inf->champions[vm_inf->champions_nbr].h.prog_size = header->prog_size;
    my_strcpy(vm_inf->champions[vm_inf->champions_nbr].h.comment,
        header->comment);
    vm_inf->champions[vm_inf->champions_nbr].h.magic = header->magic;
    vm_inf->champions[vm_inf->champions_nbr].actual_cycle = 0;
    vm_inf->champions[vm_inf->champions_nbr].mov_in_mem = 0;
}

int create_new_champion(header_t *header, struct vm_i *vm_inf,
    struct opt_value *tmp)
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
    init_info_champion(header, vm_inf);
    return SUCC;
}

int fill_arene_and_i(struct vm_i *vm_inf, uint8_t *arene, char *path_to_file,
    struct opt_value *tmp)
{
    int fd = open(path_to_file, O_RDONLY);
    int address = 0;
    header_t header_tmp;

    if (fd == ERR)
        return ERR;
    if (read(fd, &header_tmp, sizeof(header_t)) == ERR)
        return ERR;
    my_bswap(&header_tmp.magic, sizeof(int));
    if (header_tmp.magic != COREWAR_EXEC_MAGIC) {
        close(fd);
        return ERR;
    }
    my_bswap(&header_tmp.prog_size, sizeof(int));
    if (create_new_champion(&header_tmp, vm_inf, tmp) == ERR)
        return ERR;
    address = vm_inf->champions[vm_inf->champions_nbr].address;
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
    vm_inf->champions = realloc(vm_inf->champions, sizeof(struct champion) *
        (vm_inf->champions_nbr + 1));
    if (vm_inf->champions == NULL)
        return ERR;
    vm_inf->champions[vm_inf->champions_nbr].carry = END_OF_TAB;
    return SUCC;
}

int corewar(int ac, char *av[])
{
    struct vm_i vm_inf = {.champions = NULL};
    uint8_t *arene = malloc(sizeof(uint8_t) * MEM_SIZE);

    if (arene == NULL)
        return ERR;
    my_memset(arene, 0, MEM_SIZE);
    if (handle_opt_and_fill_arene(&vm_inf, arene, av) == ERR)
        return ERR;
    if (do_game(&vm_inf.champions, arene) == ERR)
        return ERR;
    return SUCC;
}
