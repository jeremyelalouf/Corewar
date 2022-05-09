/*
** EPITECH PROJECT, 2022
** starter
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "my.h"
#include "op.h"
#include "corewar.h"

int handle_to_fill_header(header_t *header, char *line, char *to_fill)
{
    char **array = my_str_to_word_array(line, "\"\n\t");

    if (array == NULL)
        return ERR;
    if (my_tablen(array) != 2)
        return ERR;
    my_strcpy(to_fill, array[1]);
    my_free_array(array);
    return SUCC;
}

int write_header(int compile_filed_fd, FILE *old_file_fd)
{
    char *line = NULL;
    size_t size = 0;
    header_t header;

    if (getline(&line, &size, old_file_fd) == -1)
        return ERR;
    if (my_strstr(line, NAME_CMD_STRING) != NULL)
        handle_to_fill_header(&header, line, header.prog_name);
    else
        return ERR;
    if (getline(&line, &size, old_file_fd) == -1)
        return ERR;
    if (my_strstr(line, COMMENT_CMD_STRING) != NULL) {
        handle_to_fill_header(&header, line, header.comment);
    } else
        return ERR;
    header.magic = my_bswap(COREWAR_EXEC_MAGIC);
    header.prog_size = my_bswap(2214);
    write(compile_filed_fd, &header, sizeof(header));
    return SUCC;
}

int fill_compiled_file(int compile_filed_fd, const char *filepath)
{
    FILE *old_file_fd = fopen(filepath, "r");

    if (old_file_fd == NULL)
        return ERR;
    if (write_header(compile_filed_fd, old_file_fd) == ERR)
        return ERR;
    return SUCC;
}

int compile(char *av[])
{
    char *compiled_name = get_new_file_name(av[1]);
    int fd = 0;

    if (compiled_name == NULL)
        return ERR;
    fd = open(compiled_name, O_CREAT | O_RDWR, 0666);
    if (fd == -1)
        return ERR;
    if (fill_compiled_file(fd, av[1]) == ERR)
        return ERR;
    close(fd);
    return SUCC;
}

int main(int argc, const char *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    if (compile((char **)argv) == ERR)
        return EXIT_ERR;
    return SUCC;
}
