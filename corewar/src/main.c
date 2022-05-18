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
#include <stdint.h>

#include "corewar.h"
#include "my.h"
#include "virtual_machine.h"

static int get_size_type(uint8_t type_param)
{
    if (type_param == T_REG) {
        return (REG_BYTE_SIZE);
    } else if (type_param == T_IND) {
        return (IND_SIZE);
    } else {
        return (DIR_SIZE);
    }
}

static int is_instruction_reg_or_index(int k, uint8_t type_param,
    int *param_size)
{
    if (TAB_INSTRUCTION[k].have_index == TRUE) {
        if (type_param != T_REG)
           *param_size = IND_SIZE;
        else
            *param_size = REG_BYTE_SIZE;
        return (TRUE);
    } else {
        return (FALSE);
    }
}

static int is_instruction_with_index(int j, uint8_t type_param,
    uint8_t instruction, int *param_size)
{
    for (int k = 0; k < NBR_OF_INSTRUCTION; ++k) {
        if (instruction == TAB_INSTRUCTION[k].instruction) {
            return (is_instruction_reg_or_index(k, type_param,
            &param_size[j]));
        }
    }
    return (FALSE);
}

int *get_read_size(uint8_t instruction, uint8_t coding_byte)
{
    int i = 0;
    int j = 0;
    uint8_t type_param = 0;
    int *param_size = malloc(sizeof(int) * 4);

    printf("%c %c\n", instruction, coding_byte);
    if (param_size == NULL)
        return NULL;
    while (j < op_tab[instruction - 1].nbr_args) {
        type_param = ((coding_byte << 2 * j & 0xff) >> 6);
        if (is_instruction_with_index(j, type_param, instruction,
        param_size)) {
            ++j;
            continue;
        }
        param_size[j] = get_size_type(type_param);
        ++j;
    }
    if (j != 4)
        param_size[j] = END_OF_TAB;
    return param_size;
}

void get_instruction(uint8_t *arene)
{
    void (*instructions[])(uint8_t *arene) = {&live, &ld, &st, &add, &sub, &and,
                                            &or, &xor, &zjmp, &ldi, &sti, &my_fork,
                                            &lld, &lldi, &lfork, &aff};
    uint8_t *p = arene;
    int *param_size;

    printf("[%u][%u][%u]\n", arene[0], arene[1], arene[2]);
    instructions[*p - 1](arene);
    printf("param: %d | %d\n", *p - 1, *p);
    param_size = get_read_size(*p, *(p + 1));
    for (int i = 0; param_size[i] != -1 && i < 4; ++i)
        printf("%d\n", param_size[i]);
    return;
}

int decriptage(char const *filepath, uint8_t *arene)
{
    int fd = open(filepath, O_RDONLY);
    int little = 0;
    header_t header;
    int nb;

    if (fd == -1)
        return -1;
    read(fd, &header, sizeof(header_t));
    little = my_bswap(header.prog_size);
    read(fd, arene, little);
    get_instruction(arene);
    close(fd);
    return 0;
}

// TODO ! on a l'arène de remplie avec un seul champion -> pouvoir mettre une infinité de champion tant que la mémoire n'est pas pleine.
// TODO ! l'étape d'après c'est de récupérer les instructions dans des structures insctructions qui sont déjà créer avec l'asm
// TODO ! ensuite exécution 

// int fd2 = open("test", O_RDWR | O_CREAT, 0666);
// write(fd2, arene, little);
// close(fd2);

int game(char const *filepath)
{
    uint8_t *arene = malloc(sizeof(uint8_t) * MEM_SIZE);

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
        return 84;
    return 0;
}
