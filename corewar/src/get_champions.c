/*
** EPITECH PROJECT, 2022
** get_champions
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"

int read_champion(struct champion *result)
{
    int fd = open(result->filepath, O_RDONLY);
    if (fd == -1) {
        my_putsterr("Error in function open: No such file or directory.\n");
        return -1;
    }
    if (read(fd, &result->h, sizeof(header_t)) == -1)
        return -1;
    // if magic number error return -1
    close(fd);
    return 0;
}

int add_player_with_num(int *index, int ac, char const *av[],
    struct champion *result)
{
    if ((*index) + 3 > ac) {
        my_putsterr("Ivalid option.\n");
        return -1;
    }
    (*index)++;
    if (handly_flag_n(index, result, av) == -1)
        return -1;
    if (handly_flag_a(index, result, av) == -1)
        return -1;
    result->actual_cycle = 0;
    result->filepath = av[*index];
    if (read_champion(result) == -1)
        return -1;
    (*index)++;
    return 0;
}

int add_player_whithout_num(UNUSED int *index, UNUSED int ac, UNUSED char const *av[],
    UNUSED struct champion *result)
{
    return 0;
}

int get_opt(struct arguments arg, int *i,  int nb_champions,
    struct champion *result)
{
    char const **av = arg.av;
    int ac = arg.ac;

    if (my_strcmp(av[*i], "-n") == 0) {
        if (add_player_with_num(i, ac, av, result + nb_champions) == -1)
            return -1;
        if (check_nb_of_all_champions(result, nb_champions,
            result[nb_champions].nb) == -1)
            return -1;
    } else
        if (add_player_whithout_num(i, ac, av, result + nb_champions) == -1)
            return -1;
    return 0;
}

int handle_dump_flag(int *index, int ac, char const *av[], int *dump)
{
    if (my_strcmp(av[*index], "-dump") == 0) {
        if (*dump > -1) {
            my_putsterr("Double definition of option dump.\n");
            return -1;
        }
        if (capture_number(index, ac, av, dump) == -1)
            return -1;
    }
    return 0;
}

struct champion *get_all_champions(int ac, const char *av[],
    int *dump, int *nb_champions)
{
    struct champion *result = init_champions();
    struct arguments arg = {.ac = ac, .av = av};
    int index = 1;

    if (result == NULL)
        return NULL;
    for (int i = index; i < ac;) {
        if (handle_dump_flag(&i, ac, av, dump) == -1)
            return NULL;
        result = realloc(result, sizeof(struct champion) * (*nb_champions + 1));
        if (result == NULL)
            return NULL;
        if (get_opt(arg, &i, *nb_champions, result) == -1)
            return NULL;
        (*nb_champions)++;
        if (handly_error_nb_champions(*nb_champions) == -1)
            return NULL;
    }
    return result;
}
