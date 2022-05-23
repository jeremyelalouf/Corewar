/*
** EPITECH PROJECT, 2022
** project
** File description:
** error_handling
*/

#include <stdlib.h>

#include "my.h"
#include "corewar.h"

static void print_help(void)
{
    my_putstr("USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n\
        file_name file in assembly language to be converted \
into file_name.cor,\nan executable in the Virtual Machine.\n");
    exit(SUCC);
}

int there_is_solo_label(char *line, char **solo_label)
{
    char **array = my_str_to_word_array(line, " ,\n\t");

    if (array == NULL)
        return FALSE;
    if (my_tablen(array) == 1 && my_char_in_str(array[0], LABEL_CHAR)
        == TRUE) {
        *solo_label = my_strdup(array[0]);
        return TRUE;
    }
    my_free_array(array);
    return FALSE;
}

int unusable_line(char *line)
{
    char **array = my_str_to_word_array(line, " ,\t\n");

    if (array == NULL)
        return TRUE;
    return FALSE;
}

int error_handling(int ac, const char *av[])
{
    if (ac < 2) {
        my_putsterr("Usage: ./asm file_name[.s] ....\n");
        return ERR;
    }
    if (my_strcmp(av[1], "-h") == 0)
        print_help();
    return SUCC;
}
