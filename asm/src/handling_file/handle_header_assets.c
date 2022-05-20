/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** handle_header_assets
*/

#include "my.h"
#include "corewar.h"

void fill_magic(header_t *header)
{
    header->magic = COREWAR_EXEC_MAGIC;
    my_bswap(&header->magic, sizeof(header->magic));
    header->prog_size = 0;
    my_bswap(&header->prog_size, sizeof(header->prog_size));
}

int handle_comment(char **line, size_t *size, FILE *old_file_fd)
{
    for (int i = 0; *line[0] == '#'; ++i)
        if (getline(line, size, old_file_fd) == ERR)
            return ERR;
    return SUCC;
}
