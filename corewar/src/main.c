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

void handle_n_flag(struct champion *c, int value)
{
    c->nb = value;
}

void handle_a_flag(struct champion *c, int value)
{
    c->address = value;
}

static const struct handle_flags FLAGS[] = {
    {.flag = "-n", .func = &handle_n_flag},
    {.flag = "-a", .func = &handle_a_flag},
};

int handle_flags(struct champion *result, char *flag, char *value)
{
    for (int i = 0; i != FLAGS_NUMBER; ++i) {
        if (my_strcmp(flag, FLAGS[i].flag) == 0) {
            FLAGS[i].func (result, my_getnbr(value));
            return SUCC;
        }
    }
    return ERR;
}

struct champion *get_all_champions(int ac, char *av[])
{
    struct champion *result = NULL;
    int champions_nbr = 0;

    for (int i = 1; av[i] != NULL; ++i) {
        result = realloc(result, sizeof(struct champion) *
            (champions_nbr + 1));
        ++champions_nbr;
        if (av[i][0] == '-') {
            if (ac > i + 1) {
                if (handle_flags(result, av[i], av[i + 1]) == ERR)
                    return NULL;
                if (ac > i + 2)
                    i += 2;
                else
                    return NULL;
            } else
                return NULL;
        }
        printf("%s\n", av[i]);
    }
    return result;
}

int corewar(int ac, const char *av[])
{
    struct champion *champions = get_all_champions(ac, (char **)av);

    if (champions == NULL)
        return ERR;
    return 0;
}

int main(int argc, char const *argv[])
{
    if (error_handling(argc, argv) == ERR)
        return EXIT_ERR;
    if (corewar(argc, argv) == ERR)
        return EXIT_ERR;
    return 0;
}
