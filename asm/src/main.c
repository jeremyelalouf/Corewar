/*
** EPITECH PROJECT, 2022
** starter
** File description:
** main
*/

#include "my.h"
#include "op.h"
#include "corewar.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

int bswap(int value)
{
    int converted = 0;

    converted |= ((0xff & value) << 24);
    converted |= (((0xff << 8) & value) << 8);
    converted |= (((0xff << 16) & value) >> 8);
    converted |= (((0xff << 24) & value) >> 24);
    return converted;
}

int compile(char *av[])
{
    int fd = open("test.cor", O_CREAT | O_RDWR, 0666);
    header_t test = {
        .prog_name = "Tyron",
        .magic = COREWAR_EXEC_MAGIC,
        .prog_size = 2214,
        .comment = "Just a basic pompes, traction program"
    };

    if (fd == -1)
        return ERR;
    test.magic = bswap(test.magic);
    test.prog_size = bswap(test.prog_size);
    write(fd, &test, sizeof(test));
    return SUCC;
}

int main(int argc, char *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    compile(argv);
    return SUCC;
}
