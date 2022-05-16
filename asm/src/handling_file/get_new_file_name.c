/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_new_file_name
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"

char *get_new_file_name(const char *av, struct pars_counter *pars_i)
{
    char *tmp = my_strdup(av);
    char *tmp_save = tmp;
    char *result = NULL;
    char *av_index = my_strrchr(tmp, '/');

    pars_i->prog_name = my_strdup(av_index);
    if (pars_i->prog_name == NULL)
        return NULL;
    tmp[my_strlen(tmp) - 1] = '\0';
    if (av_index != NULL)
        tmp = av_index;
    result = my_strcat(tmp, "cor");
    if (result == NULL)
        return NULL;
    free(tmp_save);
    return result;
}
