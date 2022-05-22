/*
** EPITECH PROJECT, 2022
** parsing_champions
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
#include <errno.h>

#include "virtual_machine.h"
#include "my.h"

// int decriptage(char const *filepath, u_int8_t *arene)
// {
//     int fd = open(filepath, O_RDONLY);
//     int little = 0;
//     header_t header;

//     if (fd == -1)
//         return -1;
//     if (read(fd, &header, sizeof(header_t)) == -1) {
//         if (errno == EISDIR)
//             my_putsterr("Error in function read: Is a directory.\n");
//         return -1;
//     }
//     if (header.magic != COREWAR_EXEC_MAGIC) {
//         my_putsterr("Wrong executable magic number.\n");
//         close(fd);
//         return -1;
//     }
//     little = my_bswap(header.prog_size);
//     if (read(fd, arene, little) == -1)
//         return -1;
//     close(fd);
//     return 0;
// }

// static char const *get_nb_cycle(char const *av[])
// {
//     for (int i = 0; av[i] != NULL; i++) {
//         if (my_strcmp(av[i], "-dump"))
//             return (av[i + 1]);
//     }
//     return NULL;
// }

// static struct champion get_champion(struct informations *info, int ac, char const *av[])
// {
//     struct champion c = {0};
//     for (int i = 1; i < ac; i++) {
//         if (my_strcmp(av[i], "-dump") == 0)
//             i += 2;
//         if (my_strcmp(av[i], "-n") == 0) {
//             i++;
//             c.nb = my_getnbr(av[i]);
//         }
//         if (my_strcmp(av[i], "-a") == 0) {
//             i++;
//         }
//     }
//     // i->nb_champions += 1;
//     // i->all_champions[0] = c;
//     return c;
// }

// int parsing_champions(int ac, char const *av[])
// {
//     struct informations i = {get_nb_cycle(av), -1, get_champion(&i, ac, av)};
//     u_int8_t *arene = malloc(sizeof(u_int8_t) * MEM_SIZE);

//     if (arene == NULL)
//         return -1;
//     if (i.nbr_cycle == NULL)
//         return -1;
//     memset(arene, 0, MEM_SIZE - 1);

//     //TODO write the scene and execute;
//     // for (int i = 0; i < ac; i++) {
//     //     if (decriptage(av[i], arene) == -1) {
//     //         free(arene);
//     //         return -1;
//     //     }
//     // }
//     free(arene);
//     return 0;
// }
