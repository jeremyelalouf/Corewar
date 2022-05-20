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

int copy_in_real_file(char *compiled_name, int fd)
{
    int real_fd = open(compiled_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
    int i = 0;
    ssize_t rd;
    ssize_t wr;
    char buffer[256];

    if (real_fd == -1)
        return ERR;
    lseek(fd, 0, SEEK_SET);
    do {
        rd = read(fd, buffer, sizeof(buffer));
        if (rd == ERR)
            return ERR;
        wr = write(real_fd, buffer, rd);
        if (wr == ERR)
            return ERR;
    } while (rd == sizeof(buffer));
    close(real_fd);
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
    fd = open(TMP_COREWAR_FILE, O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1)
        return ERR;
    if (fill_compiled_file(fd, av[1], &pars_i) == ERR) {
        close(fd);
        return ERR;
    }
    copy_in_real_file(compiled_name, fd);
    close(fd);
    return SUCC;
}
