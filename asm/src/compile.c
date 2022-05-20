/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** compile
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "my.h"
#include "corewar.h"

static int fill_compiled_file(int compile_filed_fd, const char *filepath,
    struct pars_counter *pars_i)
{
    FILE *old_file_fd = fopen(filepath, "r");
    int params_debute = 0;

    if (old_file_fd == NULL)
        return ERR;
    if (write_header(compile_filed_fd, old_file_fd, pars_i,
        &params_debute) == ERR)
        return ERR;
    if (write_champions(compile_filed_fd, old_file_fd, params_debute) == ERR)
        return ERR;
    return SUCC;
}

int compile(char *av[])
{
    struct pars_counter pars_i = {
        .line = 0,
    };
    char *compiled_name = get_new_file_name(av[1], &pars_i);
    int fd = 0;

    if (compiled_name == NULL)
        return ERR;
    fd = open(compiled_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1)
        return ERR;
    if (fill_compiled_file(fd, av[1], &pars_i) == ERR) {
        close(fd);
        return ERR;
    }
    close(fd);
    return SUCC;
}
