/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_header
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "op.h"
#include "corewar.h"

static int header_error_handling(char *command, char **array, char *line,
    struct pars_counter *pars_i)
{
    if (my_tablen(array) != 2) {
        if (my_strcmp(command, NAME_CMD_STRING) == 0 ||
        my_strcmp(command, COMMENT_CMD_STRING) == 0) {
            my_char_in_str(line, '"') == TRUE ?
                print_syntax(pars_i) :
                print_no_name(pars_i);
        } else
            print_invalid(pars_i);
        free(command);
        return ERR;
    }
    return SUCC;
}

static int fill_header(char *command, char *arg, header_t *header,
    struct pars_counter *pars_i)
{
    if (my_strcmp(command, NAME_CMD_STRING) == 0) {
        my_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
        my_strcpy(header->prog_name, arg);
    } else if (my_strcmp(command, COMMENT_CMD_STRING) != 0) {
        print_invalid(pars_i);
        return ERR;
    } if (my_strcmp(command, COMMENT_CMD_STRING) == 0) {
        my_memset(header->comment, 0, COMMENT_LENGTH + 1);
        my_strcpy(header->comment, arg);
    } else if (my_strcmp(command, NAME_CMD_STRING) != 0) {
        print_invalid(pars_i);
        return ERR;
    }
    return SUCC;
}

static int handle_to_fill_header(header_t *header, char *line,
    struct pars_counter *pars_i)
{
    char **array = my_str_to_word_array(line, "\"\n\t");
    char *command = NULL;

    if (array == NULL)
        return ERR;
    command = my_strtok(array[0], " ");
    if (header_error_handling(command, array, line, pars_i) == ERR)
        return ERR;
    if (fill_header(command, array[1], header, pars_i) == ERR)
        return ERR;
    free(command);
    my_free_array(array);
    return SUCC;
}

int write_header(int compile_filed_fd, FILE *old_file_fd,
    struct pars_counter *pars_i, int *params_debute)
{
    char *line = NULL;
    size_t size = 0;
    header_t header = {0};

    while (1) {
        if (getline(&line, &size, old_file_fd) == ERR)
            return ERR;
        if (line[0] != '#')
            break;
    }
    ++pars_i->line;
    if (handle_to_fill_header(&header, line, pars_i) == ERR)
        return ERR;
    header.magic = COREWAR_EXEC_MAGIC;
    my_bswap(&header.magic, sizeof(header.magic));
    header.prog_size = 0;
    my_bswap(&header.prog_size, sizeof(header.prog_size));
    if (getline(&line, &size, old_file_fd) == ERR)
        return ERR;
    ++pars_i->line;
    if (handle_to_fill_header(&header, line, pars_i) == ERR)
        return ERR;
    write(compile_filed_fd, &header, sizeof(header));
    *params_debute = sizeof(header);
    return SUCC;
}
