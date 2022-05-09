/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_new_file_name
*/

#include <stdlib.h>

#include "my.h"

char *get_new_file_name(const char *av)
{
    char *tmp = my_strdup(av);
    char *tmp_save = tmp;
    char *result = NULL;
    char *av_index = my_strrchr(tmp, '/');

    tmp[my_strlen(tmp) - 1] = '\0';
    if (av_index != NULL)
        tmp = av_index;
    result = my_strcat(tmp, "cor");
    if (result == NULL)
        return NULL;
    free(tmp_save);
    return result;
}
