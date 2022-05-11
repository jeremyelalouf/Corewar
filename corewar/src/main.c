/*
** EPITECH PROJECT, 2022
** main
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "my.h"
#include "op.h"
#include "virtual_machine.h"

header_t init_header_struct(void)
{
    return;
}

int decriptage(char const *filepath, u_int8_t *arene)
{
    int fd = open(filepath, O_RDONLY);
    int little = 0;
    header_t header;

    if (fd == -1)
        return -1;
    read(fd, &header, sizeof(header_t));
    little = my_bswap(header.prog_size);
    read(fd, arene, little);
    close(fd);
    return 0;
}

// TODO ! on a l'arène de remplie avec un seul champion -> pouvoir mettre une infinité de champion tant que la mémoire n'est pas pleine.
// TODO ! l'étape d'après c'est de récupérer les instructions dans des structures insctructions qui sont déjà créer avec l'asm
// TODO ! ensuite exécution 
int game(char const *filepath)
{
    u_int8_t *arene = malloc(sizeof(u_int8_t) * MEM_SIZE);

    if (arene == NULL)
        return -1;
    memset(arene, 0, MEM_SIZE - 1);
    if (decriptage(filepath, arene) == -1)
        return -1;
    free(arene);
    return 0;
}

int main(int ac, char const *av[])
{
    if (error_handling(ac, av) == -1)
        return 84;
    if (game(av[1]) == -1)
        return -1;
    return 0;
}
