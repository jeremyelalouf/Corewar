/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_header
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "my.h"
#include "op.h"
#include "corewar.h"

static int handle_to_fill_header(header_t *header, char *line, char *to_fill)
{
    char **array = my_str_to_word_array(line, "\"\n\t");

    if (array == NULL)
        return ERR;
    if (my_tablen(array) != 2)
        return ERR;
    if (my_strcmp(to_fill, NAME_CMD_STRING) == 0) {
        my_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
        my_strcpy(header->prog_name, array[1]);
    } else if (my_strcmp(to_fill, COMMENT_CMD_STRING) == 0) {
        my_memset(header->comment, 0, COMMENT_LENGTH + 1);
        my_strcpy(header->comment, array[1]);
    }
    my_free_array(array);
    return SUCC;
}

int write_header(int compile_filed_fd, FILE *old_file_fd)
{
    char *line = NULL;
    size_t size = 0;
    header_t header;

    if (getline(&line, &size, old_file_fd) == ERR)
        return ERR;
    if (my_strstr(line, NAME_CMD_STRING) != NULL)
        handle_to_fill_header(&header, line, NAME_CMD_STRING);
    else
        return ERR;
    header.magic = my_bswap(COREWAR_EXEC_MAGIC);
    header.prog_size = my_bswap(2214);
    if (getline(&line, &size, old_file_fd) == ERR)
        return ERR;
    if (my_strstr(line, COMMENT_CMD_STRING) != NULL)
        handle_to_fill_header(&header, line, COMMENT_CMD_STRING);
    else
        return ERR;
    write(compile_filed_fd, &header, sizeof(header));
    return SUCC;
}
